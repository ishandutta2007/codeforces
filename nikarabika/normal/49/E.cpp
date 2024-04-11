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

const int maxn = 50 + 1;
bitset<26> can[maxn][maxn],
	nac[maxn][maxn];
int dp[maxn][maxn],
	q;
char qu[maxn][3];
string s, t;

void fill(string &s, bitset<26> can[maxn][maxn]){
	for(int i = 0; i < sz(s); i++)
		can[i][i][s[i]-'a'] = 1;
	for(int len = 2; len <= sz(s); len++)
		for(int i = 0; i + len <= sz(s); i++)
			for(int j = i; j + 1 < i + len; j++){
				bitset<26> &tmp1 = can[i][j];
				bitset<26> &tmp2 = can[j + 1][i + len - 1];
				for(int k = 0; k < q; k++)
					if(tmp1[qu[k][1]] and tmp2[qu[k][2]])
						can[i][i + len - 1][qu[k][0]] = 1;
			}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t
		>> q;
	for(int i = 0; i < q; i++){
		cin >> qu[i][0] >> qu[i][1] >> qu[i][1] >> qu[i][1] >> qu[i][2];
		for(int j = 0; j < 3; j++)
			qu[i][j] -= 'a';
	}
	fill(s, can);
	fill(t, nac);
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i <= sz(s); i++)
		for(int j = 1; j <= sz(t); j++)
			for(int ii = i; ii > 0; ii--)
				for(int jj = j; jj > 0; jj--)
					if((can[ii - 1][i - 1] & nac[jj - 1][j - 1]).any())
						smin(dp[i][j], dp[ii - 1][jj - 1] + 1);
	cout << (dp[sz(s)][sz(t)] < 100 ? dp[sz(s)][sz(t)] : -1) << '\n';
	return 0;
}