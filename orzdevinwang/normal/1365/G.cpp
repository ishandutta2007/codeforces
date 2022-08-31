#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e4 + 7;
int n, f[N], g[N], mp[N], cnt;
ll rs[N], ns[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	cin >> n;
	for(int i = 0; cnt < n; ++i) if(__builtin_popcount(i) == 6) f[++cnt] = i, mp[i] = cnt;
	L(i, 0, 12) {
		int r = 0;
		L(j, 1, n) if(f[j] >> i & 1) ++r;
		if(!r) continue;
		cout << "? " << r;
		L(j, 1, n) if(f[j] >> i & 1) cout << ' ' << j;
		cout << endl, cin >> rs[i];
	}
	L(i, 0, 63) {
		int sum = 0;
		L(j, 0, 12) if(rs[j] >> i & 1) sum |= (1 << j);
		L(j, 1, n) if(sum && j != mp[sum]) ns[j] |= (1LL << i); 
	}
	cout << '!';
	L(i, 1, n) cout << ' ' << ns[i];
	cout << endl;
	return 0;
}