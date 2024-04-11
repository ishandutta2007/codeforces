#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 3e5 + 7;
int n, m, a[N]; 
map < int, int > mp;
map < ll, int > ct;
vi sx[N];
inline ll getid (int x, int y) {
	if(x > y) swap(x, y);
	return (ll) x * 1145141919810LL + y;
}

void Main () {
	ct.clear(), mp.clear();
	cin >> n >> m;
	L(i, 1, n) {
		cin >> a[i];
		mp[a[i]] += 1;
	}
	for(auto u : mp) 
		sx[u.second].push_back(u.first);
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		ct[getid(u, v)] = true;
	}
	
	vi S;
	L(i, 1, n) if(sz(sx[i])) {
		reverse(sx[i].begin(), sx[i].end());
		S.push_back(i);
	}
	
	ll ns = 0;
	for(const int &u : S) {
		for(const int &v : S) if(u <= v) {
			
			for(const int &a : sx[u]) {
				bool ok = true;
				for(const int &b : sx[v]) {
					if(a == b || ct[getid(a, b)]) ok = false;
					else {
						ns = max(ns, (ll) (a + b) * (u + v));
//						if((a + b) * (u + v) == 45) cout << u << ' ' << v << " : " << a << ' ' << b << '\n';
						break;
					}
				}
				if(ok) break;
			}
			
		}
	}
	
	cout << ns << '\n';
	
	L(i, 1, n) sx[i].clear();
	
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) Main ();
	
	return 0;
}