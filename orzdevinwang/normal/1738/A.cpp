#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, a[N], b[N];
vi s[2]; 
ll qwq = 0;
void Main() {
	qwq = 0;
	cin >> n;
	s[0].clear(), s[1].clear();
	L(i, 1, n) {
		cin >> a[i]; 
	}
	L(i, 1, n) {
		cin >> b[i];
		s[a[i]].push_back(b[i]);
		qwq += b[i];
	} 
	L(o, 0, 1) sort(s[o].begin(), s[o].end()), reverse(s[o].begin(), s[o].end());
	ll ns = 0;
	L(o, 0, 1) 
		L(j, 0, min(sz(s[o ^ 1]), sz(s[o])) - 1) 
			ns += s[o][j];
	if(sz(s[0]) == sz(s[1])) {
		ns -= min(s[0][sz(s[0]) - 1], s[1][sz(s[0]) - 1]);
	}
	cout << qwq + ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}