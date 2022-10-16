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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(100001)
#define ch (int)(500)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		
		vector<multiset<ll> > arr(n);
		
		fori(n){
			forj(m){
				ll ed;
				cin>>ed;
				arr[i].insert(ed);
			}
		}
		
		ll s= 0;
		
		vector<vector<ll> > all(n);
		
		fori(m){
			ll lz = -1;
			ll mn = inf;
			
			forj(n){
				if(*arr[j].begin() < mn){
					mn = *arr[j].begin();
					lz = j;
				}
			}
			
			s+=mn;
			
			forj(n){
				if(j!=lz){
					auto it = arr[j].end();
					--it;
					all[j].pb(*it);
					arr[j].erase(it);
				}
				else{
					all[j].pb(mn);
					arr[j].erase(arr[j].begin());
				}
			}
		}
		
		fori(n){
			forj(m){
				cout<<all[i][j]<<' ';	
			}
			cout<<'\n';
		}
		
		
	}
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();  
}