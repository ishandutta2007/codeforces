#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1e6 + 7;
int n, m, pra[N], prb[N];
char s[N]; 
void Main () {
	cin >> n >> m;
	cin >> (s + 1);
	L(i, 1, n) {
		pra[i] = pra[i - 1];
		prb[i] = prb[i - 1];
		if(s[i] == s[i - 1]) {
			pra[i] += s[i] == '0';
			prb[i] += s[i] == '1';
		}
	} 
	while(m--) {
		int l, r;
		cin >> l >> r;
		cout << max(pra[r] - pra[l], prb[r] - prb[l]) + 1 << '\n';
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	Main();
	return 0;
}