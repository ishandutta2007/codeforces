#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
const int buf = 111111;
int n, m, G[19][N], has[N], Pow[N];
vector< pii > Fix[19][N];  
//  Fix  Gray 
// pair<a, b> :  a  b 
int cnt[26][N];
char s[N];
ll res, ans;
int len(int x) { return (1 << (x + 1)) - 1; }
bool issame(int x, int y, int len) {
	if(x > y) swap(x, y);
	return 1ll * Pow[y - x] * (has[x + len - 1] - has[x - 1] + mod) % mod == (has[y + len - 1] - has[y - 1] + mod) % mod;
}
int getlcp(int x, int y) {
	if(x > y) swap(x, y);
	int l = 1, r = n - y + 1, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(issame(x, y, mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int getcs(int l, int r, int S) {
	return cnt[S][r] - cnt[S][l - 1];
}
ll chaf[N], Can[N][26];
void Add(int l, int r, ll x) {
	chaf[l] += x, chaf[r + 1] -= x;
}
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	Pow[0] = 1;
	L(i, 1, n) Pow[i] = 1ll * Pow[i - 1] * buf % mod;
	L(i, 1, n) has[i] = (has[i - 1] + 1ll * Pow[i] * (s[i] - 'a' + 1) % mod) % mod;//, cout << has[i] << " ";
	// puts("");
	// cout << issame(1, 4, 3) << endl;
	L(i, 1, n) G[0][i] = 1;
	L(i, 1, n) L(j, 0, 25) if(s[i] - 'a' != j) Fix[0][i].push_back(mkp(i, j));
	L(i, 1, n) {
		L(j, 0, 25) cnt[j][i] = cnt[j][i - 1];
		cnt[s[i] - 'a'][i] ++;
	}
	// cout << "You AK, wo bao ling!\n";
	L(i, 1, 17) L(j, 1, n - len(i) + 1) {
		int start = j + (1 << i), qaq = getcs(j, j + len(i) - 1, s[j + len(i - 1)] - 'a');
		// cout << j << " " << start << endl;
		bool flaga = G[i - 1][j], flagb = G[i - 1][start];
		// if(i == 2 && j == 1) cout << flaga << " " << flagb << endl;
		if(!flaga && !flagb) continue;
		if(flaga && flagb) {
			if(issame(j, start, len(i - 1))) {
				if(qaq == 1) {
					G[i][j] = 1;
					L(k, 0, 25) if(getcs(j, j + len(i) - 1, k) == 0) Fix[i][j].push_back(mkp(j + len(i - 1), k));
				}
				else {
					L(k, 0, 25) if(getcs(j, j + len(i) - 1, k) == 0) Fix[i][j].push_back(mkp(j + len(i - 1), k));
					// cout << "fengyangyang, AKIOI! George1123 AKIOI! : " << i << " " << j << endl;
				}
				//  
			}
			else {
				// cout << "(" << i << " " << j << ")" << "diff : " << j << " " << start << " len : " << len(i - 1) << endl;
				if(issame(j, start, len(i - 2)) && issame(j + (1 << (i - 1)), start + (1 << (i - 1)), len(i - 2))) {
					if(qaq - (s[j + len(i - 1)] == s[j + len(i - 2)]) == 1)
						Fix[i][j].push_back(mkp(j + len(i - 2), s[start + len(i - 2)] - 'a'));
					if(qaq - (s[j + len(i - 1)] == s[start + len(i - 2)]) == 1)
						Fix[i][j].push_back(mkp(start + len(i - 2), s[j + len(i - 2)] - 'a'));
				}
				// 
			}
			continue;
		}
		int na = getlcp(j, start), nb = getlcp(j + na + 1, start + na + 1);
		// if(i == 2 && j == 3) 
			// cout << na << " " << nb << "(" << j + na + 1 << " " << start + na + 1 << ")" << 
			// issame(j + na + 1, start + na + 1, 1) << endl;
		if(flaga && na + nb + 1 >= len(i - 1) && qaq - (s[j + len(i - 1)] == s[start + na]) == 1) 
			Fix[i][j].push_back(mkp(start + na, s[j + na] - 'a'));
		if(flagb && na + nb + 1 >= len(i - 1) && qaq - (s[j + len(i - 1)] == s[j + na]) == 1) 
			Fix[i][j].push_back(mkp(j + na, s[start + na] - 'a'));
	}
	// cout << G[1][1] << endl;
	// for(pii x : Fix[2][3]) cout << x.first << " " << x.second << endl;
	L(i, 0, 17) L(j, 1, n - len(i) + 1) if(G[i][j]) 
		res += 1ll * len(i) * len(i), Add(j, j + len(i) - 1, 1ll * len(i) * len(i));
	L(i, 0, 17) L(j, 1, n - len(i) + 1) for(pii x : Fix[i][j]) Can[x.first][x.second] += 1ll * len(i) * len(i); 
	L(i, 1, n) chaf[i] += chaf[i - 1];
	L(i, 1, n) L(j, 0, 25) ans = max(ans, Can[i][j] - chaf[i]);//, (Can[i][j]) && (cout << i << " " << j << " : " << Can[i][j] << endl, 1);
	printf("%lld\n", res + ans);
	return 0;
}