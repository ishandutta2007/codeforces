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
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define ll long long
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10, 9) + 7;
double eps = 1e-6;
ifstream in;
ofstream out;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		set<ll> odd;
		ll n;
		cin>>n;
		odd.insert(-1);
		odd.insert(inf);
		vector<ll> arr(n);
		set<ll> big;
		fori(n){
			cin>>arr[i];
			if( i > 0 && i<n-1 ){
				if(arr[i] % 2 == 1){
				//	cout<<"we insert "<<i<<endl;
					odd.insert(i);
				}
				if(arr[i] >= 2){
					big.insert(i);
				}
			}
		}
		ll ans = 0;
		while((ll)odd.size() > 2){
			if((ll)big.size() == 0){
				break;
			}
			ll id = (*big.begin());
			auto ilk = odd.begin();
			++ilk;
			if((ll)odd.size() == 3 && (*ilk) == id ){
				if((ll)big.size() == 1){
					break;
				}
				else{
					auto it = big.begin();
					++it;
					id = (*it);
				}
			}
			while(arr[id] >= 2){
				auto ita = odd.upper_bound(id);
				auto itb = odd.lower_bound(id);
				--itb;
				if((*ita) == inf && (*itb) == -1){
					break;
				}
				else{
					ans++;
					if((*itb) != -1){
						arr[(*itb)]++;
						if(arr[(*itb)] == 2){
							big.insert(*itb);
						}
						odd.erase(itb);
					}
					if((*ita)!=inf){
						arr[*ita]++;
						if(arr[*ita] == 2){
							big.insert(*ita);
						}
						odd.erase(ita);
					}
				}
				arr[id]-=2;
			}
			if(arr[id] < 2){
				big.erase(id);
			}
		}
		if((ll)odd.size() != 2){
			cout<<-1<<'\n';
		}
		else{
			for(ll i = 1; i<n-1; i++){
				ans+=arr[i]/2;
			}
			cout<<ans<<'\n';
		}
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}