#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7;
int n, m, a[N], mx = -1e9, mn = 1e9;
ll sum = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]), sum += abs(a[i]);
	if(n == 1) 
		return cout << a[1] << "\n", 0;
	if(mx < 0 && mn < 0) 
		sum += 2 * mx; 
	if(mx > 0 && mn > 0) 
		sum -= 2 * mn;
	cout << sum << "\n";
	return 0;
}