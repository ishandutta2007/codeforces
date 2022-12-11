#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll po(ll a,ll b){
	if(b==0)
		return 1;
	ll d = po(a,b/2);
	if(b%2==0)
		return (d*d)%mod;
	else
		return (((d*d)%mod)*a)%mod;
}

int main(){
	ll n,m,k;
	cin >> n >> m >> k;
	if(n%2!=m%2&&k==-1){
		cout << 0 << "\n";
		exit(0);
	}	
	--n;--m;
	n%=mod-1;
	m%=mod-1;
	if(n==0||m==0)
		cout << 1 << "\n";
	else
		cout << po(2,(n*m));
	return 0;
}