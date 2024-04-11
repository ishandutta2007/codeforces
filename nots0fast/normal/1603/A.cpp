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
#define ld long double
const ll INF = 0x3f3f3f3f;
ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;


void del(vector<ll>& arr, set<ll>& ind){
	ll cur = ind.size() + 1;
	for(auto it = ind.end(); it!=ind.begin() ;){
		--it;
		ll id = *it;
		if(arr[id] % cur != 0){
			auto itn = it;
			++itn;
			ind.erase(it);
			if(itn != ind.end()){
				return del(arr, ind);
			}
			it = itn;
		}
		--cur;
	}
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		set<ll> inds;
		vector<ll> arr(n);
		fori(n){
			inds.insert(i);
			cin>>arr[i];
		}
		del(arr, inds);
		if(inds.empty()){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
 
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}