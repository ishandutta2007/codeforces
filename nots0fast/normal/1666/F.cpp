#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = 998244353 ;
double eps = 1e-10;
ifstream in;
ofstream out;


ll pow_mod(ll a, ll b){
	a = a%modulo;
	ll has = 1%modulo;
	for(ll i = 62; i>-1; i--){
		has*=has;
		has%=modulo;
		if(((ll)1<<i)&b)
			has*=a, has%=modulo;
	}
	return has;
}

#define MAX 5005

ll fkt[MAX];
ll inv[MAX];
void pre(){
	fkt[0] = 1;
	for(ll i = 1; i<MAX; i++){
		fkt[i] = fkt[i-1] * i % modulo;
	}
	inv[MAX-1] = pow_mod(fkt[MAX-1], modulo-2);
	for(ll i = MAX-2; i>=0; i--){
		inv[i] = inv[i+1] * (i+1) % modulo;
	}
}

ll choose(ll i, ll j){
	if(i < j){
		return 0;
	}
	return fkt[i] * inv[j] % modulo * inv[i-j] % modulo;
}

void deal(){
	pre();
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		
		vector<ll> dp(n+1, 0);
		map<ll, ll> arr;
		fori(n){
			ll ed;
			cin>>ed;
			arr[ed]++;
		}
		
		ll tot = 0;
		ll ans = 0;
		for(auto& el : arr){
			ll cr = el.ss;
			vector<ll> dpn(n+1, 0);
			dpn[0]+=el.ss;
			for(ll j = 0; j<=n-1; j++){
				// we have selected 2*j + 1 of previous ones
				// (tot - 2*j - 1) of them are hanging
				
				
				if(tot >= 2 * j + 1){
					ll lef = tot - 2*j - 1;
					// we select one of current ones
					
					dpn[j+1] += dp[j] * lef * cr;	
					dpn[j+1] %= modulo;
				}
				if(j == n/2 - 1){
			//		cout<<"we at here "<<dp[j]<<endl;
					ans += dp[j] * cr;
					ans %= modulo;
				}
					
				// we dont select any of current ones
				
				dpn[j] += dp[j];
				dpn[j] %= modulo;
				
			}
			
			dp = dpn;
			
		/*	cout<<"new dps "<<endl;
			
			fori(n+1){
				cout<<dp[i]<<' ';
			}
			cout<<endl;
		*/	
			tot += el.ss;
		}
		for(auto& el : arr){
			ans *= inv[el.ss];
			ans %= modulo;
		}
		cout<<ans<<'\n';
	}
}
    

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}