//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 555;
int ch[N][2], tot, fa[N];
int dp[2][N][N];

void ins(char *s, int n) {
    int now = 0;
    L(i, 1, n) {
        if(!ch[now][s[i] - '0']) ch[now][s[i] - '0'] = ++tot;
        now = ch[now][s[i] - '0'];
    }
}
void build() {
    queue <int> q;
    L(i, 0, 1) if(ch[0][i]) q.push(ch[0][i]);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        L(i, 0, 1) 
            if(ch[u][i]) fa[ch[u][i]] = ch[fa[u]][i], q.push(ch[u][i]);
            else ch[u][i] = ch[fa[u]][i];
    }
}
int n, m, ns[N];
char s[N], t[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> (s + 1) >> (t + 1);
	ins (t, m);
	build ();
	int o = 0;
	memset(dp[o], 0x3f, sizeof(dp[o]));
	dp[0][0][0] = 0;
	L(i, 1, n) {
		o ^= 1;
		memset(dp[o], 0x3f, sizeof(dp[o]));
		int v = s[i] - '0';
		L(j, 0, tot) L(k, 0, i) 
			dp[o][ch[j][v]][k] = min(dp[o][ch[j][v]][k], dp[o ^ 1][j][k]);
		v ^= 1;
		L(j, 0, tot) L(k, 0, i) 
			dp[o][ch[j][v]][k] = min(dp[o][ch[j][v]][k], dp[o ^ 1][j][k] + 1);
		R(k, i, 1) dp[o][tot][k] = dp[o][tot][k - 1];
		dp[o][tot][0] = 1e9;
	}
	memset(ns, 0x3f, sizeof(ns));
	L(i, 0, tot) L(j, 0, n) ns[j] = min(ns[j], dp[o][i][j]);	
	L(i, 0, n - m + 1) {
		if(ns[i] > n) cout << -1 << ' ';
		else cout << ns[i] << ' '; 
	}
	return 0;
}