#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n;
V<int> v[200005];
int fa[200005],de[200005];bool vis[200005];
void dfs(int p,int d){
	de[p]=d;
	for(int i=0;i<v[p].size();i++){
		if(v[p][i]!=fa[p]){
			fa[v[p][i]]=p;
			dfs(v[p][i],d+1); 
		}
	}
}
int get(int p){
	if(de[p]!=-1)return de[p];
	return de[p]=get(fa[p])+1;
}
int main(){
	scanf("%d",&n);
	int x,y;
	FOR(i,2,n)scanf("%d%d",&x,&y),v[x].PB(y),v[y].PB(x);
	fa[1]=-1;
	dfs(1,0);
	int maxi=0,a1,a2,a3;
	FOR(i,1,n){
		if(de[i]>maxi){
			maxi=de[i];a1=i;
		}
	}
	fa[a1]=-1;
	dfs(a1,0);
	maxi=0;int ans=0;
	FOR(i,1,n){
		if(de[i]>maxi){
			maxi=de[i];a2=i;
		}
	}
	ans=maxi;
	int s=a2;
	FILL(de,-1);
	while(s!=-1){
		vis[s]=1;de[s]=0;
		s=fa[s];
	}
	maxi=0;
	FOR(i,1,n){
		if(de[i]==-1)get(i);
		if(de[i]>=maxi&&i!=a1&&i!=a2){
			maxi=de[i];a3=i;
		}
	}
	printf("%d\n%d %d %d",maxi+ans,a1,a2,a3);
	RE 0;
}