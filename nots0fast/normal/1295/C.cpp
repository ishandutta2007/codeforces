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
#define double long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,7) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;


 
void deal(){
	ll t;
	cin>>t;
	while(t--){
		map<char,vector<ll> > all;
		string a,b;
		cin>>a>>b;
		fori(a.length()){
			all[a[i]].pb(i);
		}
		ll lst = -1;
		ll sy = 1;
		fori(b.length()){
			auto it = upper_bound(all[b[i]].begin(), all[b[i]].end(), lst);
			if(it == all[b[i]].end()){
				lst = -1;
				++sy;
				auto it = upper_bound(all[b[i]].begin(), all[b[i]].end(), lst);
				if(it == all[b[i]].end()){
					sy = -1;
					break;
				}
				lst = *it;
			}
			else{
				lst = *it;
			}
		}
		cout<<sy<<'\n';
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}