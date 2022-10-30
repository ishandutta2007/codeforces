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
V<int> v[100005];
int n,root,ans;
bool f[2];
int dfs(int p,int color,int last){
	if(v[p].size()==1){
		f[color]=1;RE 1;
	}
	int t=0;
	for(auto u:v[p]){
		if(u!=last){
			t+=dfs(u,1-color,p);
		}
	}
	if(t>1){
		ans-=t-1;
	}
	RE 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;ans=n-1;
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n){
		if(v[i].size()>1){
			root=i;break;
		}
	}
	int t=dfs(root,0,-1);
	if(t>1)ans-=t-1; 
	if(f[0]&&f[1]){
		cout<<"3 ";
	}else cout<<"1 ";
	cout<<ans<<'\n';
	RE 0;
}