//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 + 85 - 69;
int dp[maxn][maxn][maxn];
pair<pii, int> par[maxn][maxn][maxn];
int go[maxn][26];
string s, t, vir;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t >> vir;
	for(int i = 0; i < sz(vir); i++)
		for(int j = 0; j < 26; j++)
			for(int k = 1; k <= i + 1; k++)
				if(vir[k - 1] == 'A' + j and vir.substr(0, k - 1) == vir.substr(i - k + 1, k - 1))
					go[i][j] = k;
	//dp[i][j][k] --> s[1..i] t[1..j] vir[1..k]
	int n = sz(s),
		m = sz(t),
		o = sz(vir);
	s = '*' + s;
	t = '*' + t;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			for(int k = 0; k <= o; k++){
				smax(dp[i][j][k], max(dp[i - 1][j][k], dp[i][j - 1][k]));
				par[i][j][k] = MP(MP(i, j), k);
				if(dp[i - 1][j][k] > dp[i][j - 1][k]) par[i][j][k].L.L--;
				else par[i][j][k].L.R--;
			}
			if(s[i] == t[j])
				for(int k = 0; k < o; k++)
					if(dp[i][j][go[k][s[i]-'A']] < dp[i - 1][j - 1][k] + 1){
						smax(dp[i][j][go[k][s[i]-'A']], dp[i - 1][j - 1][k] + 1);
						par[i][j][go[k][s[i]-'A']] = MP(MP(i - 1, j - 1), k);
					}
		}
	int virpos = max_element(dp[n][m], dp[n][m] + o) - dp[n][m],
		npos = n,
		mpos = m;
	string ret;
	while(npos and mpos){
		int nwn = par[npos][mpos][virpos].L.L,
			nwm = par[npos][mpos][virpos].L.R,
			nwv = par[npos][mpos][virpos].R;
		if(nwn == npos - 1 and nwm == mpos - 1)
			ret += s[npos];
		npos = nwn;
		mpos = nwm;
		virpos = nwv;
	}
	
	reverse(all(ret));
	cout << (sz(ret) ? ret : "0") << endl;
	return 0;
}