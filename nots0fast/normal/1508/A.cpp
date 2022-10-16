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
#define pb(a) push_back(a)
#define MAX (int)(2*pow(10,3) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = 100'000'007;


void deal(){
	srand(time(NULL));
	
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		
		vector<vector<ll> > tot(3, vector<ll>(2, 0));
		
		vector<string> arr(3);
		
		fori(3){
			cin>>arr[i];
			for(auto& f : arr[i]){
				tot[i][f-'0']++;
			}
		}
		
		string ans = "";
		
		fori(3){
			forj(i){
				fork(2){
					if(tot[i][k] >=n && tot[j][k] >= n){
						char wanted = '0' + k;
						char other = '0' + (!k);
						
						vector<ll> pt(2, 0);
						
						while(pt[0] < 2*n || pt[1] < 2*n){
							while(pt[0] < 2*n && arr[i][pt[0]] != wanted){
								ans+=other;
								++pt[0];
							}
							while(pt[1] < 2*n && arr[j][pt[1]] != wanted){
								ans+=other;
								++pt[1];
							}
							
							if(pt[0] < 2*n || pt[1] < 2*n){
								ans+=wanted;
								++pt[0];
								++pt[1];
							}
						}
						
						break;
						
					}
				}
				if(ans!= ""){
					break;
				}
			}
			if(ans != ""){
				break;
			}
		}
		
		cout<<ans<<'\n';
		
		
	}
	
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}