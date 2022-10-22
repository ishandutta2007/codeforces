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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,ans[1500005];
bool f[1500005];
void solve(){
	int m;
	cin>>n>>m;
	FOR(i,1,3*n)f[i]=0;
	int cnt=0,u,v;
	FOR(i,1,m){
		cin>>u>>v;
		if(f[u]||f[v])continue;
		f[u]=f[v]=1;
		ans[++cnt]=i;
	}
	if(cnt>=n){
		cout<<"Matching\n";
		FOR(i,1,n){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
		RE ;
	}
	cnt=0;
	FOR(i,1,3*n){
		if(!f[i]){
			ans[++cnt]=i;
		}
	}
	if(cnt<n){
		cout<<"Impossible\n";
	}else{
		cout<<"IndSet\n";
		FOR(i,1,n)cout<<ans[i]<<' ';
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}