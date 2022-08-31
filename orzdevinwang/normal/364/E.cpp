#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
#define vei vector<int>
using namespace std;
const int N = 2505;
int n, m, k;
struct GG {
	int f[8];
} f[N], g[N];
GG operator + (GG aa, GG bb) {
	GG res;
	int now = 0, zz = 0;
	L(i, 1, k + 1) {
		while(zz < k + 1 && bb.f[now + 1] < aa.f[i]) res.f[++zz] = bb.f[++now];
		if(zz == k + 1) break;
		res.f[++zz] = aa.f[i];
	}
	return res;
}
ll ans;
char s[N][N];
void work(int L, int R, int l, int r) {
	if(L == R && l == r) {
		if(k == s[L][l] - '0') ans ++;
		return;
	}
	int Lena = R - L + 1, Lenb = r - l + 1;
	if(Lena >= Lenb) {
		int mid = (L + R) >> 1, tot;
		L(i, l, r) {
			tot = 0;
			R(j, mid, L) {
				if(s[j][i] == '1') f[i].f[++tot] = - j;
				if(tot == k + 1) break;
			}
			while(tot < k + 1) f[i].f[++tot] = 1 - L;
			tot = 0;
			L(j, mid + 1, R) {
				if(s[j][i] == '1') g[i].f[++tot] = j;
				if(tot == k + 1) break;
			}
			while(tot < k + 1) g[i].f[++tot] = R + 1;
		}
		GG AA, BB; 
		L(i, l, r) {
			L(j, 1, k + 1) AA.f[j] = 1 - L, BB.f[j] = R + 1;
			L(j, i, r) {
				AA = AA + f[j], BB = BB + g[j];
				AA.f[0] = -mid, BB.f[0] = mid + 1;
				L(t, 0, k) ans += (AA.f[t + 1] - AA.f[t]) * (BB.f[(k - t) + 1] - BB.f[(k - t)]);
			}
		}
		work(L, mid, l, r);
		work(mid + 1, R, l, r);
	}
	else {
		int mid = (l + r) >> 1, tot;
		L(i, L, R) {
			tot = 0;
			R(j, mid, l) {
				if(s[i][j] == '1') f[i].f[++tot] = - j;
				if(tot == k + 1) break;
			}
			while(tot < k + 1) f[i].f[++tot] = 1 - l;
			tot = 0;
			L(j, mid + 1, r) {
				if(s[i][j] == '1') g[i].f[++tot] = j;
				if(tot == k + 1) break;
			}
			while(tot < k + 1) g[i].f[++tot] = r + 1;
		}
		GG AA, BB; 
		L(i, L, R) {
			L(j, 1, k + 1) AA.f[j] = 1 - l, BB.f[j] = r + 1;
			L(j, i, R) {
				AA = AA + f[j], BB = BB + g[j];
				AA.f[0] = - mid, BB.f[0] = mid + 1;
				L(t, 0, k) ans += (AA.f[t + 1] - AA.f[t]) * (BB.f[(k - t) + 1] - BB.f[(k - t)]);
			}
		}
		work(L, R, l, mid);
		work(L, R, mid + 1, r);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, n) cin >> s[i] + 1;
	work(1, n, 1, m);
	cout << ans << endl;
	return 0;
}