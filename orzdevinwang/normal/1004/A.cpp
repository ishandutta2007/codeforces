#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, d, a[N], ans;
map<int, int> mp;
bool check(int x) {
	int mn = 2e9 + 5;
	L(i, 1, n) mn = min(mn, abs(a[i] - x));
	return mn == d;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> n >> d;
	L(i, 1, n) cin >> a[i], mp[a[i] - d] = 1, mp[a[i] + d] = 1;
	for(pii g : mp) 
		if(check(g.first)) ans ++;
	cout << ans << "\n";
	return 0;
}