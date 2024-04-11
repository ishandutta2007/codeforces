/*

DP





ll int
 dp 










*/
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
int n,f[100],tf[200005],siz[200005];
V<P<int,int> > v[200005];
void get(int x,int lst,V<int> &tv,V<int> &ts,V<int> &fa){
	siz[x]=1;
	for(auto u:v[x])if(u.F!=lst&&!u.S){
//		if(u.F==4&&x==3){
//			cout<<"!!!\n";
//		}
		get(u.F,x,tv,ts,fa);
		siz[x]+=siz[u.F];
	}
	tv.PB(x);ts.PB(siz[x]);fa.PB(lst);
}
bool dfs(int x){
	V<int> tv,ts,fa;
	get(x,-1,tv,ts,fa);
	if(!tf[ts.back()]){
		RE 0;
	}
	if(tf[ts.back()]<=4)RE 1;
	rep(i,0,tv.size()){
		if(tf[ts[i]]==tf[ts.back()]-2||tf[ts[i]]==tf[ts.back()]-1){
			for(auto &u:v[fa[i]])if(u.F==tv[i]){
				u.S=1;
			}
			for(auto &u:v[tv[i]])if(u.F==fa[i]){
				u.S=1;
			}
			if(dfs(fa[i])&&dfs(tv[i]))RE 1;
			else RE 0;
		} 
	}
//	cout<<x<<' ';
//	for(auto u:tv){
//		cout<<u<<' ';
//	}
//	cout<<'\n';
	RE 0;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n;
	int x,y;
	f[1]=f[2]=1;tf[1]=2;
	FOR(i,3,27){
		f[i]=f[i-1]+f[i-2];
		tf[f[i]]=i;
	}
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(MP(y,0));
		v[y].PB(MP(x,0));
	}
	if(dfs(1)){
		cout<<"YES";
	}else cout<<"NO";
	RE 0;
}