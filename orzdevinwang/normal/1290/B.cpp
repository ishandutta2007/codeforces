#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, m, pre[N][26];
char s[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> (s + 1), n = strlen(s + 1);
	L(i, 1, n) {
		L(j, 0, 25) pre[i][j] = pre[i - 1][j] ;
		pre[i][s[i] - 'a'] += 1;
	}
	cin >> m;
	while (m--) {
		int l, r, cnt = 0;
		cin >> l >> r;
		if(s[l] != s[r] || l == r) {
			cout << "Yes\n";
			continue;
		}
		L(i, 0, 25) if(pre[r][i] - pre[l - 1][i] > 0) cnt += 1;
		if(cnt > 2) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}