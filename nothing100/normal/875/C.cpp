#include<bits/stdc++.h>
#define LL long long
#define mo 1000000007
using namespace std;
int n,m,num[100010],ans;
vector<int> s[100010],edge[100010];
int en[100010];
queue<int> q;
void dfs(int index,int l,int r){
	while (l<=r&&s[l].size()==index) l++;
	if (l>=r) return;
	for (int i=l;i<=r;i++)
	if (s[i].size()==index){
		printf("No\n");
		exit(0);
	}
	while (l<=r){
		int tmp=l;
		while (tmp<=r&&s[tmp][index]==s[l][index]) tmp++;
		dfs(index+1,l,tmp-1);
		if (tmp<=r) edge[s[tmp][index]].push_back(s[l][index]),en[s[l][index]]++;
		l=tmp;
	}
}
int main() {
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++) num[i]=i;
	int o,p;
	for (int i=1;i<=m;i++){
        scanf("%d",&o);
        while (o--){
        	scanf("%d",&p);
			s[i].push_back(p);
        }
	}
	dfs(0,1,m);
	//cout<<ans<<endl;
	for (int i=1;i<=n;i++)
	if (en[i]==0) q.push(i);
	while (!q.empty()){
		o=q.front();
		if (num[o]+n<=0){
			printf("No\n");
			return 0;
		}
		else if (num[o]<=0) ans++;
		for (int i=0;i<edge[o].size();i++){
			en[edge[o][i]]--;
			if (!en[edge[o][i]]) q.push(edge[o][i]);
			while (num[edge[o][i]]>num[o]) num[edge[o][i]]-=n;
		}
		q.pop();
	}
	//cout<<ans<<endl;
	for (int i=1;i<=n;i++)
	if (en[i]){
		printf("No\n");
		return 0;
	}
	printf("Yes\n%d\n",ans);
	for (int i=1;i<=n;i++)
	if (num[i]<=0) printf("%d ",i);
}