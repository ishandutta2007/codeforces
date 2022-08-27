#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n, tp[N];
ll a[N], ns[N];
vector < ll > s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
		int lg = 0;
		L(Z, 0, 60) if(a[i] >> Z & 1) lg = Z;
		s[lg].push_back(a[i]);
	}
	ll now = 0;
	L(a, 1, n) {
		bool ok = true;
		L(i, 0, 60) if((!(now >> i & 1)) && tp[i] < sz(s[i])) {
			ns[a] = s[i][tp[i]++], now ^= ns[a], ok = false;
			break;
		}
		if(ok) return cout << "No\n", 0;
	}
	cout << "Yes\n";
	L(i, 1, n) cout << ns[i] << " ";
	cout << "\n";
	return 0;
}