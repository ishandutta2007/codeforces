#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
#define mp make_pair
#define Y second
#define X first
using namespace std; 
const long long int N=1e5+20,mod=1e9+7;


ll s[N],DP[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cout.tie(0);
	ll n,k;
	cin >> n >> k;
	if (k != 1)s[1] = 1;
	else s[1] = 2;
	if (k != 1) DP[1] = 1;
	else DP[1] = 2;
	DP[0]= 1;
	s[0] = 0;
	rep (i,2,N){
		if (k <= i){
			DP[i] = (DP[i-1] + DP[i-k])%mod;
		}
		else{
			DP[i] = DP[i-1];
		}
		if (DP[i] == 0){
			DP[i] = mod;
		}
	}
	rep (i,2,N){
		 s[i] = (s[i-1] + DP[i])%mod;
	}
	rep (i,0,n){
		ll l,r;
		cin >> l >> r;
		cout << (s[r]-s[l-1]+mod)%mod << endl;
//		cout << s[r] << "  " <<  s[l-1] << endl;
	}
}