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
ll r[N],l[N],a[N];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(false);	
	//cout.tie(0);
	ll n,t=0;
	cin >>n;
	rep (i,0,n){
		cin >> a[i];
		if (i && a[i] <= 0) t++;
	}
	if (t == 0){
		cout << 1;
		return 0;
	}
	
	l[0] = 0;
	r[0] = t;
	if (a[0] >= 0) l[0]++;
	rep (i,1,n-1){
		l[i] = l[i-1];
		r[i] = r[i-1];
		if (a[i]>0) l[i]++;
		if (a[i] < 0) r[i]--;
		//cout << l[i] << " " << r[i] << endl;
	}
	ll ans = INT_MAX;
	rep (i,0,n-1){
		ans = min (ans,l[i]+r[i]);
//		if (ans == 1) cout << l[i] << " " << r[i] <<endl;
	}
	cout  << ans;
}