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
	int ns = 10;
	cin >> (s + 1), n = strlen(s + 1);
	L(m, 0, (1 << n) - 1) {
		bool ok = true;
		L(i, 1, n) {
			int c = m >> (i - 1) & 1;
			if((c ^ 1) == s[i] - '0') ok = false;
		}
		if(!ok) continue;
		
		int now = 0, c1 = 5, c2 = 5;
		L(i, 1, n) {
			int c = m >> (i - 1) & 1;
			if(i % 2 == 0) {
				--c2, now -= c;
			}
			else {
				--c1, now += c;
			}
			if(now - c2 > 0) ns = min(ns, i);
			if(now + c1 < 0) ns = min(ns, i);
		}
	}
	cout << ns << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}