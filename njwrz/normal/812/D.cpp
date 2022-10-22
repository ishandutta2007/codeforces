#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int l[100005],r[100005];
int last[100005],cnt;
V<int> v[100005]; 
void dfs(int p,int fa){
	l[p]=++cnt;
	for(auto u:v[p])if(u!=fa)dfs(u,p);
	r[p]=cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q,k;
	cin>>n>>m>>q>>k;
	int x,y;
	FOR(i,1,q){
		cin>>x>>y;
		if(last[y])v[last[y]].PB(x);
		last[y]=x;
	}
	FOR(i,1,n)if(!l[i])dfs(i,-1);
	int t;
	FOR(i,1,k){
		cin>>x>>y;
		t=last[y];
		if(l[x]<=l[t]&&r[x]>=r[t]){
			cout<<r[x]-l[x]+1<<'\n';
		}else{
			cout<<"0\n";
		}
	}
	RE 0;
}