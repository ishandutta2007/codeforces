#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1e3 + 7;
bitset < N > bs[N], ma[N]; 
int n, And[N][N], cnt[N];
bool vis[N], ed[N][N];
vi e[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n) {
		cin >> cnt[i];
		L(j, 1, cnt[i]) {
			int u;
			cin >> u;
			bs[u].set (i);
			ma[i].set (u);
		}
	}
	vi hp;
	L(i, 1, n) if(bs[i].count() == n) hp.push_back(i);
	if(sz(hp) > 1) {
		if (sz(hp) == n) L(i, 2, n) cout << 1 << ' ' << i << '\n';
		else { 
			assert (sz(hp) == 2);
			cout << hp[0] << ' ' << hp[1] << '\n';
			int p = -1;
			L(i, 1, n) if(bs[i].count() != n) p = i;	
			L(i, 1, n) if(bs[i].count() != n) {
				if(bs[i] == bs[p]) cout << i << ' ' << hp[0] << '\n';
				else cout << i << ' ' << hp[1] << '\n';
			}
		}
		return 0;
	}
	L(i, 1, n) L(j, i + 1, n) {
		auto x = ma[i] & ma[j];
		if(x.count() == 2) {
			int a = x._Find_first();
			int b = x._Find_next(a);
			if(!ed[a][b]) 
				ed[a][b] = true, e[a].push_back(b), e[b].push_back(a), cout << a << ' ' << b << '\n';
		}
		else And[i][j] = And[j][i] = x.count();
	}
	L(i, 1, n) if(!sz(e[i])) {
		L(j, 1, n) vis[j] = false;
		int cnt = 0;
		L(j, 1, n) if(sz(e[j]) && (bs[i] & bs[j]) == bs[i]) vis[j] = true, cnt += 1;
		L(j, 1, n) if(vis[j] && cnt == sz(e[j]) + 1) {
			bool ok = true;
			for (const int &v : e[j]) if(!vis[v]) ok = false;
			if(ok) cout << i << ' ' << j << '\n';
		}
	}
	return 0;
}