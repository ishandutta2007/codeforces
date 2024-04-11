/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/

#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll int
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,9);
ll modulo = 1000007;
double eps = 1e-6;
ifstream in;
ofstream out;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<vector<ll> > times(n+10);
		vector<ll> pts(n+10, 0);
		vector<ll> arr(n);
		fori(n){
			ll ed;
			cin>>ed;
			arr[i] = ed;
			times[ed].pb(i);
		}
		fori(n+10){
			times[i].pb(inf);
		}
		ll pt = 0;
		vector<ll> ans;
		while(pt < n){
			ll topush = 0;
			ll mx = -1;
			forj(n+10){
				ll lst = pts[j];
				if(times[j][lst] == inf){
					break;
				}
				mx = max(mx, times[j][lst]);
				topush = j+1;
			}
			if(topush == 0){
				while(pt < n){
					ans.pb(0);
					++pt;
				}
			}
			else{
				while(pt<= mx){
					ll ed = arr[pt];
					++pts[ed];
					++pt;
				}
				ans.pb(topush);
			}
		}
		cout<<ans.size()<<'\n';
		for(auto& el : ans){
			cout<<el<<' ';
		}
		cout<<'\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}