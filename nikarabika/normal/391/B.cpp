//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1000 + 85 - 69;
int dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i < sz(s); i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++)
			if(s[i] == s[j] and ((i - j) & 1))
				smax(dp[i], dp[j] + 1);
	}
	cout << *max_element(dp, dp + sz(s)) << endl;
	return 0;
}