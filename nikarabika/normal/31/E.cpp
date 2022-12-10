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

const int maxn = 40;
LL dp[maxn][maxn], P[maxn], par[maxn][maxn];
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = P[i - 1] * 10;
	cin >> s >> s;
	for(int i = sz(s) - 1; i >= 0; i--){
		for(int j = 0; j <= sz(s) - i; j++){
			LL pnt1, pnt2;
			if(j == 0)
				dp[i][j] = dp[i + 1][j] + (s[i] - '0') * P[sz(s) - i - 1], par[i][j] = j;
			else if(j == sz(s) - i)
				dp[i][j] = dp[i + 1][j - 1] + (s[i] - '0') * P[j - 1], par[i][j] = j - 1;
			else if((pnt1 = dp[i + 1][j - 1] + (s[i] - '0') * P[j - 1]) > (pnt2 = dp[i + 1][j] + (s[i] - '0') * P[sz(s) - i - j - 1]))
				dp[i][j] = pnt1, par[i][j] = j - 1;
			else
				dp[i][j] = pnt2, par[i][j] = j;
		}
	}
	int row = 0, col = sz(s) / 2;
	while(row < sz(s)){
		if(par[row][col] == col)
			cout << 'H';
		else
			cout << 'M';
		col = par[row][col];
		row++;
	}
	return 0;
}