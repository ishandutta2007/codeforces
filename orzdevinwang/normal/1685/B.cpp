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
int a, b, c, d;
char s[N];
int col[N];
void Main () {
	cin >> a >> b >> c >> d;
	cin >> (s + 1);
	int n = strlen(s + 1);
	int cnta = 0, cntb = 0;
	L(i, 1, n) 
		if(s[i] == 'A') 
			cnta += 1;
		else 
			cntb += 1;
	if(cnta != a + c + d) 
		return cout << "NO\n", void ();
	L(i, 0, n + 1) col[i] = 0;
	L(i, 1, n - 1) {
		if(s[i] == 'A' && s[i + 1] == 'B') 
			col[i] = 1;
		if(s[i] == 'B' && s[i + 1] == 'A') 
			col[i] = 2;
	}
	
	vi v[2];
	
	int len = 0, fi = 0, cnt = 0;
	L(i, 1, n) {
		if(col[i]) {
			if(!len) fi = col[i] - 1;
			++len;
		} else if(len) {
			cnt += len / 2;
			if(len & 1) 
				v[fi].emplace_back(len / 2 + 1);
			len = fi = 0;
		}
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	
	
	for(auto &u : v[0]) {
		while(u && c) --u, --cnt, --c; 
		if(!u) ++cnt;
	}
	
	for(auto &u : v[1]) {
		while(u && d) --u, --cnt, --d; 
		if(!u) ++cnt;
	} 
	
//	cout << c + d << '\n';
	
	if(c + d <= cnt) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
} 
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t ;
	cin >> t;
	while(t--) Main();
	return 0;
}