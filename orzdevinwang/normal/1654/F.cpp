#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 19, mod = 998244353;
int n, rk[N], ord[N], pr[N];
char s[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	L(i, 0, (1 << n) - 1) 
		rk[i] = s[i] - 'a';
	L(o, 0, n - 1) {
		L(i, 0, (1 << n) - 1) 
			ord[i] = i;
		sort(ord, ord + (1 << n), [&] (int x, int y) {
			return rk[x] == rk[y] ? rk[x ^ (1 << o)] < rk[y ^ (1 << o)] : rk[x] < rk[y];
		});
		int cnt = 1;
		L(i, 0, (1 << n) - 1)  {
			if(i && (rk[ord[i]] != rk[ord[i - 1]] || 
				rk[ord[i] ^ (1 << o)] != rk[ord[i - 1] ^ (1 << o)])) 
					cnt += 1;
			pr[ord[i]] = cnt; 
		}
		L(i, 0, (1 << n) - 1) 
			rk[i] = pr[i];
	}
	L(i, 0, (1 << n) - 1) 
		if(rk[i] == 1) {
			L(j, 0, (1 << n) - 1) 
				cout << s[i ^ j];
			return 0;
		}
	assert(false);
	return 0;
}