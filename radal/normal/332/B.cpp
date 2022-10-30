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
const long long int mod=1e8,N=2e5+10;
ll s[N],a[N];
pair<ll,ll> mx[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cout.tie(0);
	ll n,k;
	cin >>n >> k;
	rep(i,0,n){
		cin >> a[i];
	}
	rep (i,0,k){
		s[0] +=  a[i];
	}
	rep(i,k,n){
		s[i-k+1] = s[i-k]+a[i]-a[i-k];
		
	}
	mx[n-k].X = s[n-k];
	mx[n-k].Y = n-k;
	repr (i,n-k-1,0){
		if (s[i]  >= mx[i+1].X){
			mx[i].X = s[i];
			mx[i].Y = i;
		}
		else{
			mx[i] = mx[i+1];
		}
		//cout << mx[i].X << " ";
	}
	ll ans=0,p=0,b=1;
	rep (i,0,n-k){
		if (s[i] + mx[i+k].X > ans){
			ans = mx[i+k].X+s[i];
			p = i;
			b = mx[i+k].Y;
		}
		//cout << s[i] << "  " << mx[i+k].X << endl;
	}
	cout << p+1 << " "<<b+1;
}