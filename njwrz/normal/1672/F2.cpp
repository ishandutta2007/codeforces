#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
int in[200005],n,a[200005],b[200005],cnt[200005];
V<int> v[200005];
void solve(){
	cin>>n;
	FOR(i,1,n)in[i]=cnt[i]=0,v[i].clear();
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i],cnt[b[i]]++;
	int mx=1;
	FOR(i,2,n)if(cnt[i]>cnt[mx])mx=i;
	FOR(i,1,n){
		if(a[i]!=mx&&b[i]!=mx){
			v[a[i]].PB(b[i]);
			in[b[i]]++;
		}
	}
	queue<int> q;
	FOR(i,1,n)if(!in[i])q.emplace(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto u:v[x])if(--in[u]==0){
			q.emplace(u);
		}
	}
	FOR(i,1,n)if(in[i]){
		cout<<"WA\n";RE;
	}
	cout<<"AC\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}