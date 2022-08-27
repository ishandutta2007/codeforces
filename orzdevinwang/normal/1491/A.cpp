#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, f[N], cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> f[i], cnt += f[i];
	while(m--) {
		int opt, x;
		cin >> opt >> x;
		if(opt == 1) {
			cnt -= f[x];
			f[x] ^= 1; 
			cnt += f[x]; 
		}
		else {
			if(cnt >= x) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}