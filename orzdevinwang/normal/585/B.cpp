#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 10;
int n, k;
char s[4][N];
void Main () {
	cin >> n >> k;
	L(i, 0, 2) cin >> (s[i] + 1);
	int msk = 0;
	L(i, 0, 2) if(s[i][1] == 's') msk |= 1 << i;
	L(i, 1, n) {
		L(j, 0, 2) if('A' <= s[j][i] && s[j][i] <= 'Z') 
			msk ^= msk & (1 << j);
		if(i % 3 == 2) {
			int x = msk;
			msk = 0;
			if(x & 1) msk |= 3;
			if(x & 2) msk |= 7;
			if(x & 4) msk |= 6;
		}
		L(j, 0, 2) if('A' <= s[j][i] && s[j][i] <= 'Z') 
			msk ^= msk & (1 << j);
		// cout << msk << '\n';
	}
	if(msk) cout << "YES\n";
	else cout << "NO\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}