#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int V, n, a[N], ns[N];
bool need[N];
int cur, ret;
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> V >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) {
		ret += a[i];
		if(i < n) need[ret % V] = true;
	}
	cur += 1;
	L(i, 1, V) {
		ns[cur] += 1;
		if(need[i]) cur += 1;
	}
	cout << (ret + V -  1) / V << '\n';
	L(i, 1, n) cout << ns[i] << ' ';
	cout << '\n';
	cur = 1;
	L(i, 1, n) {
		while (a[i] > 0) {
			cout << i << ' ';
			a[i] -= ns[cur], cur += 1;
			if(cur > n) cur = 1, cout << '\n';
		}
	}
	if(cur != 1) while (cur <= n) cout << n << ' ', cur += 1;
	return 0;
}