#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e13 + 7;
const int max_n = 2001, max_k = 2001;
int n, k;
vector<vector<bool>> num;

bool a[max_n][7];

int get(int id, int nu) {
	int res = 0;
	for(int i = 0;i < 7;i++) {
		if (a[id][i] && !num[nu][i]) res = inf;
		if (!a[id][i] && num[nu][i]) res++;
	}
	return min(res, inf);
}

string q(int r) {
	if (r == 0) return "1110111";
	if (r == 1) return "0010010";
	if (r == 2) return "1011101";
	if (r == 3) return "1011011";
	if (r == 4) return "0111010";
	if (r == 5) return "1101011";
	if (r == 6) return "1101111";
	if (r == 7) return "1010010";
	if (r == 8) return "1111111";
	if (r == 9) return "1111011";
}



void scan() {
	cin >> n >> k;
	for(int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for(int j = 0;j < 7;j++) a[i][j] = s[j] == '1';
	}

	num.resize(10, vector<bool>(7));

	for(int i = 0;i < 10;i++) {
		string qq = q(i);
		for(int j = 0;j < 7;j++) num[i][j] = qq[j] == '1';
	}
}

void solve() {
	scan();

	vector<vector<int>> b(n, vector<int>(10));
	vector<vector<bool>> dp(n, vector<bool>(k + 1));


	for(int i = 0;i < n;i++) {
		for(int j = 0;j < 10;j++) b[i][j] = get(i, j);
	}
	
	//cout << "b" << endl;

	for(int i = n - 1;i >= 0;i--) {
		for(int j = 0;j <= k;j++) {
			//cout << i << " " << j << endl;
			for(int q = 0;q < 10;q++) {
				int next_j = j - b[i][q];

				//if (j == 3) cout << next_j << endl;
				if (next_j < 0) continue;
				if (i == n - 1 && next_j == 0) dp[i][j] = true;
				else if (i != n - 1 && dp[i + 1][next_j]) dp[i][j] = true;
			}
		}
	}

	//cout << "scan" << endl;

	if (!dp[0][k]) cout << -1;
	else{
		for(int i = 0;i < n;i++) {
			for(int j = 9;j >= 0;j--) {
				int next_k = k - b[i][j];

				//cout << j << " " << next_k 
				if (next_k < 0) continue;
				if ((i == n - 1 && next_k == 0) || (i != n - 1 && dp[i + 1][next_k])) {
					cout << j;
					k = next_k;
					break;
				} 
			}
		}
	}
}





	
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   	solve();

}