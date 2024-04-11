#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1507;
int n, m, p[N], a[N][N], b[N][N], pre[N][N], ans[N], top, cnt[N];
struct tk {
	int w, id;
} PP[N];
int sortk;
bool cmp(tk aa, tk bb) {
	return a[aa.w][sortk] == a[bb.w][sortk] ? aa.id < bb.id : a[aa.w][sortk] < a[bb.w][sortk];
}
void Sort(int l, int r, int k) {
	sortk = k;
	L(i, l, r) PP[i].w = p[i], PP[i].id = i;
	sort(PP + l, PP + r + 1, cmp);
	L(i, l, r) p[i] = PP[i].w;
}
int scnt[N], v[N], tot, nw[N], nwtot;
bool vis[N]; 
void Main() {
	cin >> n >> m;
	L(i, 1, n) L(j, 1, m) cin >> a[i][j];
	L(i, 1, n) L(j, 1, m) cin >> b[i][j];
	L(j, 1, m) R(i, n, 1) 
		if(i == n || b[i][j] > b[i + 1][j]) pre[i][j] = i;
		else pre[i][j] = pre[i + 1][j];
	v[1] = tot = 1, v[tot + 1] = n + 1;
	L(i, 1, m) scnt[i] = (pre[1][i] < n);
	while(1) { 
		int pos = 0;
		L(i, 1, m) if(!vis[i] && !scnt[i]) {
			pos = i;
			break;
		}
		if(!pos) break;
		vis[pos] = true, ans[++top] = pos, nwtot = 0;
		L(i, 1, tot) {
			int las = v[i];
			L(j, v[i] + 1, v[i + 1] - 1) if(b[j - 1][pos] != b[j][pos]) {
				L(k, 1, m) scnt[k] -= (pre[las][k] < v[i + 1] - 1);
				L(k, 1, m) scnt[k] += (pre[las][k] < j - 1);
				L(k, 1, m) scnt[k] += (pre[j][k] < v[i + 1] - 1);
				nw[++nwtot] = j, las = j;
			}
		}
		while(nwtot) v[++tot] = nw[nwtot--];
		sort(v + 1, v + tot + 1), v[tot + 1] = n + 1;
	}
	L(i, 1, n) p[i] = i;
	reverse(ans + 1, ans + top + 1);
	L(i, 1, top) Sort(1, n, ans[i]);
	L(i, 1, n) L(j, 1, m) if(a[p[i]][j] != b[i][j]) return cout << "-1\n", void();
	cout << top << "\n";
	L(i, 1, top) cout << ans[i] << " ";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}