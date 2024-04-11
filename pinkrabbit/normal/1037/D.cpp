#include<bits/stdc++.h>
using namespace std;
int n,x,y,a[200001],b[200001],A[200001],c;
vector<int> G[200001];
int que[200001],l,r;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i) scanf("%d%d",&x,&y), G[x].push_back(y), G[y].push_back(x);
	for(int i=1;i<=n;++i) scanf("%d",a+i), b[a[i]]=i;
	for(int i=1;i<=n;++i) sort(G[i].begin(),G[i].end(),[](int x,int y){return b[x]<b[y];});
	que[l=r=1]=1;
	while(l<=r){
		int u=que[l++];
		A[++c]=u;
		for(int i:G[u]) if(b[i]>b[u]) que[++r]=i;
	}
	for(int i=1;i<=n;++i) if(a[i]!=A[i]) return 0*puts("No");
	return 0*puts("Yes");
}