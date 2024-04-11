#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, m, f[N];
vector < pair < int, int > > ns, t1, t2;
char s[N], t[N];

void make (char *s, int n) {
	ns.clear();
	
	auto kth = [&] (int k) {
		if(!k) return 0;
		int cnt = 0; 
		L(i, 1, n) if(s[i] == '1') {
			++cnt;
			if(cnt == k) return i;
		}
		return -1;
	} ;
	
	auto ins = [&] (int l, int r) {
		ns.push_back(make_pair(l, r)), reverse(s + l, s + r + 1);
		return ;
	};
	
	int c = 0;
	L(i, 1, n) c += s[i] - '0'; 
	
	if(m == 0 || c < m) 
		return ;
	
	if(m == c) {
		int p = n, ok = false;
		while (s[p] == '0') --p;
		ins (1, p); 
		p = n;
		while (s[p] == '0') --p;
		L(i, 1, p) {
			if(s[p - i + 1] < s[i]) ok = true;
			if(s[p - i + 1] != s[i]) break;
		}
		if(ok) ins (1, p);
		return ;
	}
	
	L(i, 1, c - m - 1) ins (i, kth (i + m - 1));
	
	L(r, 1, m) 
		if(r & 1) ins (kth (c - m) + 1, kth (c));
		else ins (kth (c - m), kth (c) - 1);
	
	if(m & 1) {
		L(r, 1, m + 1) 
			if(r & 1) 
				ins (kth (c - m - 1) + 1, kth (c) - 1);
			else 
				ins (kth (c - m) + 1, kth(c));
	}
//	L(i, 1, n) cout << s[i];
//	cout << "\n";
} 
void Main () {
	cin >> n >> m;
	cin >> (s + 1) >> (t + 1);
	
	make (s, n), t1 = ns, make (t, n), t2 = ns;
	
	L(i, 1, n) if(s[i] != t[i]) return cout << "-1\n", void (); 
	
	cout << sz(t1) + sz(t2) << "\n";
	L(i, 0, sz(t1) - 1) cout << t1[i].first << " " << t1[i].second << "\n";
	R(i, sz(t2) - 1, 0) cout << t2[i].first << " " << t2[i].second << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main () ;
	return 0;
}