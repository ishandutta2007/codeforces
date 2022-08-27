#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;

const int N = 1e5 + 7; 

char s[N], t[N];
int n, m, cnt[3];
void Main() {
	cin >> (s + 1) >> (t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	me(cnt, 0);
	L(i, 1, n) {
		cnt[s[i] - 'A'] ^= 1;
	}
	L(i, 1, m) {
		cnt[t[i] - 'A'] ^= 1;
	}
	L(i, 0, 2) if(cnt[i]) {
		return cout << "NO\n", void ();
	} 
	vi ta, tb;
	L(i, 1, n) if(s[i] != 'B') {
		ta.emplace_back(s[i] - 'A');
		if(sz(ta) > 1 && ta[sz(ta) - 1] == ta[sz(ta) - 2]) 
			ta.pop_back(), ta.pop_back();
	}
	L(i, 1, m) if(t[i] != 'B') {
		tb.emplace_back(t[i] - 'A');	
		if(sz(tb) > 1 && tb[sz(tb) - 1] == tb[sz(tb) - 2]) 
			tb.pop_back(), tb.pop_back();
	} 
	if(ta == tb) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0; 
}