#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 1005;

int n, p[N], idx, vis[N], ty;
char s[N][N];
int main() {
	cin >> n;
	rep(i, 1, n) rep(j, 1, n) s[i][j] = '.';
	rep(i, 1, n) scanf("%d", &p[i]);
	rep(i, 1, n) if(!vis[i] && p[i] ^ i) {
		ty = 1;
		int j = i, ls = idx;
		for(vis[i] = 1; idx++, p[j] ^ i; vis[j = p[j]] = 1) if(j ^ 1)
			s[idx][j] = s[idx][p[j]] = j < p[j] ? '/' : '\\';
		s[idx][j] = s[idx][1] = '\\'; if(i ^ 1) s[ls + 1][1] = '/';
	}
	cout << n - ty << endl;
	rep(i, 1, n) puts(s[i] + 1);
	return 0;
}