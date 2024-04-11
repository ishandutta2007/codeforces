#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define lll __int128
#define pb(a) push_back(a)
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
const ll modulo = pow(10,9) + 7;

void deal(){
	int t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<vector<ll> > g(n);
		vector<ll> in(n, 0);
		vector<ll> mx(n, -1);
		fori(n){
			ll ed;
			cin>>ed;
			forj(ed){
				ll ch;
				cin>>ch;
				--ch;
				g[ch].pb(i);
				in[i]++;
			}
		}
		vector<ll> bfs;
		fori(n){
			if(!in[i]){
				bfs.pb(i);
				mx[i] = 1;
			}
		}
		fori((ll)bfs.size()){
			ll hd = bfs[i];
			for(auto& hr : g[hd]){
				--in[hr];
				if(hd > hr){
					mx[hr] = max(mx[hr], mx[hd] + 1);
				}
				else{
					mx[hr] = max(mx[hr], mx[hd]);
				}
				if(!in[hr]){
					bfs.pb(hr);
				}
			}
		}
		ll ans = 0;
		fori(n){
			ans = max(ans, mx[i]);
		} 
                if(bfs.size() != n){
                      ans = -1;
                }
		cout<<ans<<'\n';
	}
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}