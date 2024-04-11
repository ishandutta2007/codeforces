#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 8007;
int n, fi, dis[N][N], col[N], cnt[N], deg[N];
int ord1[N], ord2[N], l1, l2, len1[N], len2[N];
bool G[N][N];
char s[N][N / 4];
inline int get (char c) {
	return '0' <= c && c <= '9' ? c - '0' : 10 + c - 'A';
}
bool vis[N];
ll ns;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> (s[i] + 1);
	L(i, 1, n) L(j, 1, n) G[i][j] = get(s[i][(j + 3) >> 2]) >> (3 - ((j - 1) & 3)) & 1, deg[i] += G[i][j]; 
	L(i, 1, n) vis[i] = true;
	R(i, n - 1, 1) {
		bool ok = false;
		L(j, 1, n) if(deg[j] == i) {
			ok = true;
			vis[j] = false;
			ns += (ll) i * n * 614 + i;
			break ;
		}
		if(!ok) break ;
	}
	R(i, n, 1) if(vis[i]) fi = i;
	col[fi] = 1, l1 = 1; 
	L(i, fi + 1, n) if(vis[i]) {
		if(!G[fi][i]) col[i] = 1, ++l1;
		else col[i] = 2, ++l2;
	}
	L(i, 1, n) 
		L(j, 1, n) 
			if(vis[i] && vis[j] && G[i][j] && col[i] == col[j]) 
				cnt[i] += 1;
	L(i, 1, n) if(vis[i]) {
		if(col[i] == 1) ord1[cnt[i] + 1] = i;
		if(col[i] == 2) ord2[cnt[i] + 1] = i;
	}
	ns += (l1 + l2) * (l1 + l2 - 1) * 3;
	L(i, 1, l1) {
		len1[i] = 0;
		while (len1[i] < l2 && G[ord1[i]][ord2[l2 - len1[i]]]) ++ len1[i];
//		cout << len1[i] << ", "; 
	}
//	cout << '\n';
	L(i, 1, l2) {
		len2[i] = 0;
		while (len2[i] < l1 && G[ord2[i]][ord1[l1 - len2[i]]]) ++ len2[i];
//		cout << len2[i] << ", ";
	}
//	cout << '\n'; 
	L(i, 1, l1) 
		ns -= 2 * ((i - 1) + len1[i]), ns -= l2 - len1[i] + len2[l2 - len1[i] + 1];
	L(i, 1, l2) {
		ns -= 2 * ((i - 1) + len2[i]);
		if(len2[i]) {
			ns -= l1 - len2[i]; 
			ns -= len1[l1 - len2[i] + 1];
		} else ns -= len2[1];
	}
	cout << ns << '\n';
	return 0;
}