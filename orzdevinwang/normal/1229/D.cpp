#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define u128 __int128
using namespace std;
const int N = 2e5 + 7, M = 6;
int n, k, p[N][M], w[N], tp, s[M], nw[M], mp[N];
int rk[128][M], to[128][128];
u128 mark[128][128];
int ha (int *p) {
	int ret = 0;
	L(i, 1, k) ret *= k, ret += p[i] - 1;
	return ret;
}
int getv (int *p) { return mp[ha(p)]; }
u128 z[N];
int tot, pos[N];
ll ns;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> k;
	L(i, 1, k) s[i] = i;
	do {
		mp[ha(s)] = tp;
		L(i, 1, k) rk[tp][i] = s[i];
		tp++;
	} while (next_permutation(s + 1, s + k + 1));
	L(i, 0, tp - 1) {
		L(j, 1, k) s[j] = rk[i][j];
		L(j, 0, tp - 1) {
			L(h, 1, k) s[h] = rk[i][rk[j][h]];
			to[i][j] = getv(s);
		}
	}
	L(i, 0, tp - 1) {
		L(j, 0, tp - 1) {
			u128 now = i, ret = 0;
			L(k, 0, tp - 1) 
				ret |= ((u128) 1) << now, now = to[now][j];
			mark[i][j] = ret;
		}
	}
	L(i, 1, n) L(j, 1, k) cin >> p[i][j];
	L(i, 1, n) w[i] = getv(p[i]);
	L(i, 1, n) {
		++tot, z[tot] = 1, pos[tot] = i;
		pos[tot + 1] = i + 1;
		L(j, 1, tot) {
			if(j < tot) z[j] |= z[j + 1];
			L(lala, 0, 3) 
				L(l, 0, tp - 1) if(z[j] >> l & 1) 
					L(c, j + 1, tot + 1) z[j] |= mark[l][w[pos[c] - 1]] | mark[w[pos[c] - 1]][l];
		}
		int T = 0;
		L(j, 1, tot) {
			if(!T || z[T] != z[j]) ++T, z[T] = z[j], pos[T] = pos[j];
		}
		tot = T;
		pos[tot + 1] = i + 1;
		L(j, 1, tot) {
			int nt = 0;
			L(r, 0, tp - 1) if(z[j] >> r & 1) nt += 1;
			ns += nt * (pos[j + 1] - pos[j]);
		}
	} 
	cout << ns << '\n';
	return 0;
}