#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 505;
int n, a[N], b[N], G[N][N];
vector < pair < int, int > > S; 
void put(int l, int r) {
	S.push_back({l, r});
	assert(a[l] == a[r]);
	assert(l <= r);
	assert(l >= 1 && r <= n);
	reverse(a + l, a + r + 1); 
}

void Main() {
	S.clear();
	cin >> n;
	L(i, 1, n) cin >> a[i];	
	L(i, 1, n) cin >> b[i];
	a[n + 1] = b[n + 1] = 0;
	if(!(a[1] == b[1] && a[n] == b[n])) return cout << "NO\n", void ();
	L(i, 1, n) L(j, 1, n) G[i][j] = 0;
	L(i, 1, n - 1) {
		G[a[i]][a[i + 1]] += 1;
		G[a[i + 1]][a[i]] += 1;
		G[b[i]][b[i + 1]] -= 1;
		G[b[i + 1]][b[i]] -= 1;
	}
	L(i, 1, n) L(j, 1, n) if(G[i][j]) return cout << "NO\n", void();
	cout << "YES\n";
	L(i, 2, n) {
		int V = a[i - 1];
		if(b[i] != a[i]) {
			L(j, i + 1, n) if(a[j] == b[i] && a[j + 1] == V) {
				put(i - 1, j + 1);
				break ;
			}
		}
		if(b[i] != a[i]) {
			int lst = 0;
			L(j, i, n) if(a[j] == V) lst = j;
			L(j, i, lst - 1) if(a[j] == V && a[j + 1] == b[i]) {
				put(j, lst);
				put(i - 1, lst);
				break ;
			}
			if(b[i] == a[i]) continue ;
			if(!(a[lst] == V && a[lst + 1] == b[i])) assert(false);
			bool ok = false;
			L(x, i, lst - 1) {
				L(y, lst + 1, n) if(a[x] == a[y]) {
					put(x, y);
					put(i - 1, x + y - lst);
					ok = true; 
					break ;
				}
				if(ok) break ;
			}
			if(!ok) {
				cout << "QAQ" << endl;
				L(i, 1, n) cerr << a[i] << ' ';
				cerr << '\n';
				L(i, 1, n) cerr << b[i] << ' ';
				cerr << '\n'; 
				while(true);
			} 
		}
		if(a[i] != b[i]) assert(false);
	}
	L(i, 1, n) assert(a[i] == b[i]);
	cout << sz(S) << '\n';
	for(auto u : S) cout << u.first << ' ' << u.second << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}
/*
1
7
4 7 8 2 8 4 2
4 2 8 4 7 8 2
*/