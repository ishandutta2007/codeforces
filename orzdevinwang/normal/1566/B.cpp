#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, cnt[N];
char s[N]; 
void Main () {
	cin >> (s + 1), n = strlen(s + 1);
	cnt[0] = cnt[1] = 0;
	L(i, 1, n) cnt[s[i] - '0'] += 1; 
	if(!cnt[0]) cout << 0 << '\n';
	else if(!cnt[1]) cout << 1 << '\n';
	else {
		int l = 1, r = n, ok = 1;
		while (s[l] == '1') ++ l;
		while (s[r] == '1') -- r;
		L(i, l, r) if(s[i] == '1') ok = 0;
		if(ok) cout << 1 << '\n';
		else cout << 2 <<'\n'; 
	}
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}