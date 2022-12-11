#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
FILE*FP=freopen("text.in","r",stdin);
//FILE*fp=freopen("text.out","w",stdout);
#endif
#define N 200005
vector<int>a[N]; 
queue<int>q; 
queue<int>temp;
int t,n,to[N];
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(to,0,sizeof(int)*(n+2));
		for(int i=1;i<=n;i++)a[i].clear();
		while(q.size())q.pop();	
		while(temp.size())temp.pop();	
		for(int i=1;i<=n;i++){
			scanf("%d",&to[i]);
			a[to[i]].push_back(i);
		}
		for(int i=1;i<=n;i++)
			if(a[i].size()==0)q.push(i);
		printf("%d\n",n-q.size());
		for(int i=1;i<=n;i++){
			int cnt=a[i].size();
			if(cnt>=2)
			for(int j=0;j<a[i].size();j++){
				while(q.size()){
					int te=q.front(),t2=a[i][j];
					if(a[i][j]!=q.front()){
						a[q.front()].push_back(a[i][j]);
						to[a[i][j]]=q.front();
						a[i][j]=-1;
						cnt--;
						q.pop();
						break;
					}
					temp.push(q.front());
					q.pop();
				}
				while(temp.size()){
					int te=temp.front();
					q.push(temp.front());
					temp.pop();
				}
				if(cnt==1){
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",to[i]);
		}
		putchar('\n');
		
	}
	return 0;
}
/*
 
1 2 3 4 5 6 7
  4   2 6 1
  	  5	  3
  	  	  7


 
1 2 3 4 5 6 7
5 4 7 2 6 1 3
 
  	  	  
1 2 3 4 5 6 7
6 4 6 2 4 5 6

*/