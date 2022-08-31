#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e6 + 7;
int n, m, a[N];
char s[N], t[N]; 
void Main () {
	cin >> (s + 1) >> (t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	L(i, 1, n) {
		int now = 1;
		L(j, i, n) {
			if(s[j] != t[now]) break; 
			if(now == m) return cout << "YES\n", void();
			int c = now;
			R(k, j - 1, 1) {
				++c;
				if(s[k] != t[c]) break;
				if(c == m) return cout << "YES\n", void();
			}
			++now;
		}
	}
	cout << "NO\n"; 
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}