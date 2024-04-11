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
#define ld long double
#define MAX (int)(2*pow(10,7) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		vector<set<char> > seen(2);
		vector<vector<char> > arr(n, vector<char>(m));
		fori(n){
			forj(m){
				cin>>arr[i][j];
				if(arr[i][j] != '.'){
					seen[(i+j)%2].insert(arr[i][j]);
				}
			}
		}
		if((ll)seen[0].size() > 1 || (ll)seen[1].size() > 1 ||
			( seen[0].size() && seen[1].size() && (*seen[0].begin()) == (*seen[1].begin()) ) ){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		fori(2){
			if((ll)seen[i].size() == 0){
				if(seen[!i].find('R') == seen[!i].end()){
					seen[i].insert('R');
				}
				else{
					seen[i].insert('W');
				}
			}
		}
		fori(n){
			forj(m){
				arr[i][j] = (*seen[(i+j)%2].begin());
			}
		}
		fori(n){
			forj(m){
				cout<<arr[i][j];
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