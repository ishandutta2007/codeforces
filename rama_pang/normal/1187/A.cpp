#include <bits/stdc++.h>
#define ll long long
#define db(x) cout << "=======>> " << #x << " is " << x << endl
#define pb push_back
#define fi first
#define se second
#define pii pair<ll,ll>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define rep(i,j,k,l) for (int i=(j); i<=(k); i+=(l))
#define repr(i,j,k,l) for (int i=(j); i>=(k); i-=(l))
using namespace std;


int main (){
	IOS;
	int T;
	cin>>T;
	while (T--){
		ll n,s,t;
		
		cin>>n>>s>>t;
		ll both= (s+t)-n;
		s-= both;
		t-= both;
		ll k=max(s,t)+1;
		cout <<k<<endl;
	}
	
}