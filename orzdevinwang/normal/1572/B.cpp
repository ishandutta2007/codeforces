#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 5e5 + 7;
int n, a[N];
vi S;
void cc (int x) {
	a[x] = a[x + 1] = a[x + 2] = a[x] ^ a[x + 1] ^ a[x + 2];
	S.push_back(x);
}
void solve1 (int l, int r) {
	int p1 = l;
	while (p1 <= r && !a[p1]) p1 += 1;
	if(p1 > r) return ;
	if(a[p1 + 1] == 1) cc(p1 - 1); 
	else {
		cc(p1);
		if(a[p1]) cc(p1 - 1);
	}
	solve1 (p1, r);
}
void solve2 (int l, int r) {
	int p1 = r;
	while (p1 >= l && !a[p1]) p1 -= 1;
	if(p1 < l) return ;
	if(a[p1 - 1] == 1) cc(p1 - 1); 
	else {
		cc(p1 - 2);
		if(a[p1]) cc(p1 - 1);
	}
	solve2 (l, p1);
}
void Main () {
	S.clear ();
	cin >> n;
	L(i, 1, n) cin >> a[i];
	int xsum = 0;
	L(i, 1, n) xsum ^= a[i];
	if(xsum) {
		cout << "NO\n";
		return ;
	}
	bool ok = false;
	if(!a[1]) solve1 (1, n), ok = true;
	else if(!a[n]) solve2 (1, n), ok = true;
	else {
		int ls = -1, cnt = 0;
		L(i, 1, n) if(a[i]) {
			if(ls != -1 && !a[i - 1] && ((i - ls) % 2 == 0 || cnt == 0)) {
				if(cnt) {
					for (int j = ls; j < i; j += 2) cc(j);
					for (int j = i; j > ls; j -= 2) cc(j - 2);
					solve2 (1, ls);
					solve1 (i, n); 
				}
				else solve2 (1, ls + 1), solve1 (i - 1, n); 
				ok = true;
				break ;
			} 
			ls = i, cnt ^= 1;
		}
	}
	if(!ok) return cout << "NO\n", void ();
	cout << "YES\n" << sz(S) << "\n";
	for (int x : S) cout << x << " ";
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}