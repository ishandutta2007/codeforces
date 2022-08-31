#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 233;
int n, p, q, cnt[N];
int ad(int x, int op) {
	L(i, 2, p) while(x % i == 0) cnt[i] += op, x /= i;
	return x;
}
unsigned int ns, C[N], Ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> p >> q, C[0] = 1, ns = 1, p = min(p, n - 1);
	L(i, 1, p) {
		ns *= ad(n - i + 1, 1), ad(i, -1), C[i] = ns;
		L(j, 2, p) L(k, 1, cnt[j]) C[i] *= j;
	}
	L(i, 1, q) {
		unsigned zzc = 0, now = 1;
		L(j, 0, p) zzc += now * C[j], now *= i;
		Ans ^= zzc * i;
	}
	cout << Ans << "\n";
	return 0;
}