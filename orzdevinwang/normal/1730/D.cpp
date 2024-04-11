#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7; 
int n, a[N], b[N];
char S[N], T[N];
void Main() {
	cin >> n >> (S + 1) >> (T + 1);
	set < pair < int, int > > s;
	L(i, 1, n) {
		pair < int, int > qwq = make_pair(S[i], T[n - i + 1]);
		if(qwq.first > qwq.second) swap(qwq.first, qwq.second);
		if(s.find(qwq) != s.end()) {
			s.erase(qwq);
		} else {
			s.insert(qwq);
		}
	}
	if(sz(s) != (n & 1)) return cout << "NO\n", void();
	if(sz(s) && (*s.begin()).first != (*s.begin()).second) cout << "NO\n";
	else cout << "YES\n";
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}