#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],pre[10010];
vector<int> ans[3];
queue<int> q;
void getans(int x,int y){
	if (pre[x]==1000000) return;
	getans(pre[x],y);
	int tmp=x^pre[x],cnt=2;
	for (int i=0;i<y;i++)
	if (tmp&(1<<i)) ans[cnt--].push_back(n-i-1);
}
int bfs(int x,int y){
	memset(pre,0xff,sizeof(pre));
	pre[x]=1000000;
	q.push(x);
	while (!q.empty()){
		int now=q.front();
		q.pop();
		for (int i=0;i<y;i++)
		for (int j=1;i+2*j<y;j++){
			int tmp=now^(1<<i)^(1<<(i+j))^(1<<(i+2*j));
			if (pre[tmp]==-1){
				pre[tmp]=now;
				q.push(tmp);
			}
		}
	}
	if (pre[0]!=-1){
		getans(0,y);
		return 1;
	}
	return 0;
}
int solve(int x){
    if (n-x<=13){
    	int tmp=0;
		for (int i=x;i<n;i++) tmp=tmp*2+a[i];
		return bfs(tmp,n-x);
    }
    else {
		int tmp=a[x]*4+a[x+1]*2+a[x+2];
		vector<int> one;
		if (tmp==6){
			a[x]^=1;
			a[x+1]^=1;
			ans[0].push_back(x);
			ans[0].push_back(x+1);
			for (int i=0;i<3;i++)
			if (a[x+3+i]==1) one.push_back(x+3+i);
			if (one.size()==3){
				ans[1].push_back(x+4);
				ans[2].push_back(x+8);
				a[x+4]^=1;
				a[x+8]^=1;
				ans[1].push_back(x+3);
				ans[2].push_back(x+5);
				a[x+3]^=1;
				a[x+5]^=1;
			}
			else if (one.size()==2){
				ans[1].push_back(one[0]);
				ans[2].push_back(2*one[0]-x);
				a[one[0]]^=1;
				a[2*one[0]-x]^=1;
				ans[1].push_back(one[1]);
				ans[2].push_back(2*one[1]-(x+1));
				a[one[1]]^=1;
				a[2*one[1]-(x+1)]^=1;
			}
			else if (one.size()==1){
				ans[1].push_back(one[0]);
				ans[2].push_back(2*one[0]-x);
				a[one[0]]^=1;
				a[2*one[0]-x]^=1;
				ans[1].push_back(x+6);
				ans[2].push_back(x+11);
				a[x+6]^=1;
				a[x+11]^=1;
			}
			else{
				ans[1].push_back(x+6);
				ans[2].push_back(x+12);
				a[x+6]^=1;
				a[x+12]^=1;
				ans[1].push_back(x+7);
				ans[2].push_back(x+13);
				a[x+7]^=1;
				a[x+13]^=1;
			}
		}
		else{
			for (int i=0;i<3;i++)
			if (a[x+i]==1) one.push_back(x+i);
			if (one.size()>0){
				ans[0].push_back(one[0]);
				a[one[0]]^=1;
				if (one.size()==1){
					a[one[0]+3]^=1;
					a[one[0]+6]^=1;
					ans[1].push_back(one[0]+3);
					ans[2].push_back(one[0]+6);
				}
				else{
					a[one[1]]^=1;
					a[2*one[1]-one[0]]^=1;
					ans[1].push_back(one[1]);
					ans[2].push_back(2*one[1]-one[0]);
				}
			}
		}
		return solve(x+3);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    if (solve(0)){
        printf("YES\n%d\n",(int)ans[0].size());
        for (int i=0;i<ans[0].size();i++){
            printf("%d %d %d\n",ans[0][i]+1,ans[1][i]+1,ans[2][i]+1);
        }
    }
    else printf("NO\n");
}