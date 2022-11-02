#pragma GCC optimize(3)
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
vector<int> v[500005];
int n,sub[500005];
P<int,int> ans[500005];
void get(int p,int fa){
	sub[p]=1;
	for(int i=0;i<v[p].size();i++){
		if(v[p][i]!=fa){
			get(v[p][i],p);
			sub[p]+=sub[v[p][i]];
		}
	}
}
void dfs(int p,int r,int fa){
	if(p!=1)ans[p].F=r-v[p].size();
	else ans[p].F=r-v[p].size()-1;
	int last=ans[p].F;
	int l=0; 
	for(int i=0;i<v[p].size();i++){
		if(v[p][i]!=fa){
			ans[v[p][i]].S=ans[p].F+l+1;l++;
			dfs(v[p][i],last,p);
			last-=sub[v[p][i]]*2-1;
		}
	}
}
signed main(){
	int m;
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].PB(y);v[y].PB(x);
	}
	get(1,-1);
	ans[1].S=2*n;
	dfs(1,2*n,-1);
	FOR(i,1,n){
		printf("%d %d\n",ans[i].F,ans[i].S);
	}
	RE 0;
}