#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, m;
ll a[N];
map < ll, int > mp;
bool ns;
void solve(ll x) {
	if(mp.count(x) && mp[x]) return mp[x] -= 1, void ();
	if(!ns) return ;
	if(x == 1) return ns = false, void ();
	solve(x >> 1);
	solve(x - (x >> 1));
} 
void Main() {
	mp.clear();
	ll sum = 0;
	ns = true;
	cin >> n;
	L(i, 1, n) cin >> a[i], mp[a[i]] += 1, sum += a[i];
	solve(sum);
	if(ns) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}