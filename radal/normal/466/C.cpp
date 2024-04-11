#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(ll i=l; i<r; i++)
#define repr(i,r,l) for(ll i=r; i>=l; --i)
#define pb push_back
#define mp make_pair
#define Y second
#define X first
using namespace std; 
const long long int mod=1e8,N=5e5+10;
ll a[N],s[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cout.tie(0);
	ll n,sum=0;
	cin >> n;
	rep (i,0,n){
		cin >> a[i];
		sum += a[i];
	}
	if (abs(sum)%3 || n<3){
		cout << 0;
		return 0;
	}
	sum/=3;
	ll t=0;
	ll ans=0;
	s[0]=a[0];
	if (s[0] == sum)  t++;
	rep(i,1,n){
		s[i] = s[i-1]+a[i];
		if (s[i] == 2*sum && i < n-1){
			ans+=t;	
		}
		if (s[i] == sum){
			t++;
		}
		//cout << s[i] << " ";
	}
	//cout << endl;
	cout << ans;
	
}