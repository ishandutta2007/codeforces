#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
const long long mod = 1000002649;
 
int n;
string s;
int cnt[N][26];
long long pw[N];
long long hs[N];
 
int correct[N][20];
list < pair < int, int > > poss[N][20];
long long sum[N], tot = 0;
long long specific[N][26];
 
long long gsum[N];
 
long long get(int l, int r) {
	return (hs[r] - hs[l - 1] * pw[r - l + 1] + mod * mod) % mod;
}
 
int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
 
	cin >> s; s = " " + s;
	n = s.size() - 1;
 
	for(int i = 0; i <= 20; ++i) {
		int len = (1 << (i + 1)) - 1;
		if(i) gsum[i] = gsum[i - 1];
		gsum[i] += 1LL * len * len;
	}
 
	for(int i = 1; i <= n; ++i) {
		int x = s[i] - 'a';
		for(int j = 0; j < 26; ++j) cnt[i][j] = cnt[i - 1][j];
		++cnt[i][x];
	}
 
	pw[0] = 1;
	for(int i = 1; i <= n; ++i){
		pw[i] = pw[i - 1] * 31 % mod;
		hs[i] = hs[i - 1] * 31 + (s[i] - 'a');
		hs[i] %= mod;
	}
 
	for(int i = 1; i <= n; ++i){
		correct[i][0] = 1;
		for(int c = 0; c < 26; ++c) {
			if(c == s[i] - 'a') continue;
			specific[i][c] = 1;
			poss[i][0].push_back(make_pair(i, c));
		}
	}
 
	for(int j = 1; j < 20; ++j) {
		for(int i = 1; i <= n; ++i) {
			int len = (1 << (j)) - 1;
			if(i <= len || i + len > n) continue;
 
			int cenL = i - (len >> 1) - 1;
			int cenR = i + (len >> 1) + 1;
 
			int countmid = cnt[i + len][s[i] - 'a'] - cnt[i - len - 1][s[i] - 'a'];
			long long hsL = get(i - len, i - 1), hsR = get(i + 1, i + len);
 
 
			if(countmid == 1 && hsL == hsR && correct[cenL][j - 1]) {
				correct[i][j] = 1;
			}
 
			/// changes in cenR
			if(correct[cenL][j - 1]) {
				for(auto &p : poss[cenR][j - 1]) {
					long long nw = hsR + (p.second - s[p.first] + 'a') * pw[len - (p.first - i)] + mod * mod;
					nw %= mod;
 
					int newcnt = countmid;
					if(s[p.first] == s[i]) --newcnt;
					if(p.second == s[i] - 'a') ++newcnt;
 
					if(nw == hsL && newcnt == 1) {
						poss[i][j].push_back(p);
						specific[p.first][p.second] += (1LL * (len * 2 + 1) * (len *  2 + 1));
					}
				}
			}
 
			if(correct[cenR][j - 1]) {
				for(auto &p : poss[cenL][j - 1]) {
					long long nw = hsL + (p.second - s[p.first] + 'a') * pw[i - p.first - 1] + mod * mod;
					nw %= mod;
					int newcnt = countmid;
					if(s[p.first] == s[i]) --newcnt;
					if(p.second == s[i] - 'a') ++newcnt;
 
					if(nw == hsR && newcnt == 1) {
						poss[i][j].push_back(p);
						specific[p.first][p.second] += (1LL * (len * 2 + 1) * (len *  2 + 1));
					}
				}
			}
 
			if(correct[cenL][j - 1] && hsL == hsR) {
				for(int c = 0; c < 26; ++c) {
					if(c == s[i] - 'a') continue;
					int w = cnt[i + len][c] - cnt[i - len - 1][c];
					if(w == 0) {
						specific[i][c] += (1LL * (len * 2 + 1) * (len *  2 + 1));
						poss[i][j].push_back(make_pair(i, c));
					}
				}
			}
		}
	}
 
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 20; ++j) {
			if(!correct[i][j]) break;
			int len = (1 << (j)) - 1;
			tot += (2 * len + 1) * 1LL * (2 * len + 1);
			sum[i - len] += (2 * len + 1) * 1LL * (2 * len + 1);
			sum[i + len + 1] -= (2 * len + 1) * 1LL * (2 * len + 1);
		}
	}
 
	long long ans = tot;
	for(int i = 1; i <= n; ++i) {
		sum[i] += sum[i - 1];
		for(int c = 0; c < 26; ++c) {
			ans = max(ans, tot - sum[i] + specific[i][c]);
		}
	}
 
	cout << ans << endl;
 
  return 0;
}