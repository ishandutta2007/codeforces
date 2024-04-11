#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e5+20;
int main(){ 
    ios:: sync_with_stdio(false); 
    string s;
    ll T;
    cin >> T;
    while (T--){
    	ll a,b,c;
    	cin >> a >> b >> c;
    	ll d = (c-a)*(c-a)+b*b;
    	ll ans = sqrt(d);
    	if (ans*ans != d) ans++;
    	cout << ans << endl;
	}
}