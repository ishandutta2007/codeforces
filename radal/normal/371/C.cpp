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
//#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=5e1+30,inf = 1e18;
int n[3],p[3],t[3];
ll r;
bool check (ll m){
	return r >= max(m-m,(m*t[0]-n[0]))*p[0]+max(m-m,(m*t[1]-n[1]))*p[1]+max(m-m,(m*t[2]-n[2])*p[2]);
}
ll binar(ll l,ll r){
	ll m;
	if (check(r)) return r;
	while (r-l > 1){
		m = (l+r)/2;
		if (check(m)) l = m;
		else r = m;
	}
	return l;
}
int main(){
	ll ans = 0;
	string s;
	cin >> s;
	rep(i,0,s.size()){
		if (s[i] == 'B') t[0]++;
		if (s[i] == 'S') t[1]++;
		if (s[i] == 'C') t[2]++;
	}
	cin >> n[0] >> n[1] >> n[2];
	cin >> p[0] >> p[1] >> p[2];
	cin >> r;
	ans = binar(0,2e12+1);
	cout << ans;
}