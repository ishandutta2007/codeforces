#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
#define rs(x) resize(x)
using namespace std;
const int N = 1e5 + 33, M = 33;
template < int N > struct zfun {
	char s[N];
	int z[N];
	void work (int n) {
		L(i, 1, n) z[i] = 0;
		int p = 1;
		L(i, 2, n) {
			if(z[p] + p >= i) z[i] = min(z[p] + p - i, z[i - p + 1]);
			while (i + z[i] <= n && s[i + z[i]] == s[z[i] + 1]) ++ z[i];
			if(i + z[i] > p + z[p]) p = i;
		}
		z[1] = n;
	}
};
zfun < N * 2 > Z;
char s[M][N];
int n, pre[N], len[N];
int deg[N];
inline int P(int x, int y) {
	return pre[x - 1] + y;
}
int lcp[M][N];
bool ok[N];
vi G[N];
bool solve(int l, int r) {
	queue < int > q;
	int tl = pre[l - 1] + 1, tr = pre[r]; 
	me(deg, 0), me(ok, 0);
	L(i, 0, pre[n]) G[i].clear();
	L(i, l, r) {
		L(j, 1, len[i]) {
			L(k, l, r) {
				int L = lcp[k][P(i, j)], to = j + L - 1;
				if(len[i] == len[k] && j == 1 && to == len[i]) continue ;
				if(to == len[i] && L == len[k]) {
					G[P(i, j)].emplace_back(0);	
				} else if(to == len[i]) {
					G[P(i, j)].emplace_back(P(k, L + 1));
				} else if(L == len[k]) {
					G[P(i, j)].emplace_back(P(i, j + L));
				}
			}
		}
	}
	L(i, 1, n) G[0].emplace_back(P(i, 1));
	int cnt = 1;
	ok[0] = true;
	L(i, tl, tr) ok[i] = true, cnt += 1;
	L(i, 0, pre[n]) if(ok[i]) for(const int &v : G[i]) if(ok[v]) deg[v] += 1;
	L(i, 0, pre[n]) if(ok[i] && !deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front();
		cnt -= 1;
		q.pop();
		for(const int &v : G[u]) if(ok[v]) {
			deg[v] -= 1;
			if(!deg[v]) q.push(v);
		}
	}
//	if(l == 1 && r == 3) L(u, 0, pre[n]) for(const int &v : G[u]) cout << u << " -> " << v << endl;
//	if(cnt) cout << l << " and " << r << endl;
	return cnt == 0; 
}
char cc[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> (s[i] + 1), len[i] = strlen(s[i] + 1);
	L(i, 1, n) pre[i] = pre[i - 1] + len[i];
	L(i, 1, n) L(j, pre[i - 1] + 1, pre[i]) cc[j] = s[i][j - pre[i - 1]];
	L(i, 1, n) {
		L(j, 1, len[i]) Z.s[j] = s[i][j];
		L(j, 1, pre[n]) Z.s[j + len[i]] = cc[j];
		Z.work(len[i] + pre[n]);
		L(j, 1, pre[n]) lcp[i][j] = min(Z.z[j + len[i]], len[i]);
	} 
	L(i, 1, n) L(j, pre[i - 1] + 1, pre[i]) L(k, 1, n) lcp[k][j] = min(lcp[k][j], pre[i] - j + 1);	
	int ns = 0;
	int pr = 0; 
	L(i, 1, n) {
		pr = max(pr, i - 1);
		while(pr < n && solve(i, pr + 1)) ++pr; 
		ns += pr - i + 1;
	}
	cout << ns << '\n';
	return 0;
}