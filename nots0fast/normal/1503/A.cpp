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
#define double long double
#define MAX (int)(pow(10,6) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;


bool ok(string& a){
	ll s = 0;
	for(auto& f : a){
		if(f == '('){
			++s;
		}
		else{
			--s;
		}
		if(s < 0){
			return 0;
		}
	}
	if(s!= 0){
		return 0;
	}
	return 1;
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		vector<string> ans(2);
		
		fori(n){
			forj(2){
				ans[j]+='?';
			}
		}
		
		bool bad = 0;
		ll tot = 0;
		fori(n){
			if(s[i] == '0'){
				tot++;
			}
		}
		
		if(tot%2 != 0){
			bad = 1;
		}
		else{
			ll ones = 0;
			fori(n){
				if(s[i] == '0'){
					ans[0][i] = '(';
					ans[1][i] = ')';
					swap(ans[0], ans[1]);
				}
				else{
					ones++;
				}
			}
			
			vector<ll> count(2, 0);
			
			fori(n){
				if(s[i] == '1'){
					forj(2){
						if(count[j] < ones/2){
							++count[j];
							ans[j][i] = '(';
						}
						else{
							ans[j][i] = ')';
						}
					}
				}
			}
			
			if(!ok(ans[0]) || !ok(ans[1])){
				bad = 1;
			}
		}
		
		if(bad){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n"<<ans[0]<<"\n"<<ans[1]<<'\n';
		}
		
		
		
		
	}
}

 
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}