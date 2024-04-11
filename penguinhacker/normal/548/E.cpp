#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, cnt=0;
ll ans=0;
bool vis[200000];
vector<int> f[200000];
int oc[500001];

inline void ins(int sign, int prod) {ans+=sign*(oc[prod]++);}
inline void remove(int sign, int prod) {ans-=sign*(--oc[prod]);}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		for (int j=2; j*j<=a; ++j) {
			if (a%j) continue;
			f[i].push_back(j);
			while(a%j==0) a/=j;
		}
		if (a>1) f[i].push_back(a);
		assert(f[i].size()<=6); //2*3*5*7*11*13*17>500000
	}
	while(q--) {
		int ind; cin >> ind, --ind;
		if (!vis[ind]) ans+=cnt++;
		else ans-=--cnt;
		for (int i=1; i<(1<<(int)f[ind].size()); ++i) {
			int k=__builtin_popcount(i), prod=1;
			for (int j=0; j<f[ind].size(); ++j)
				if (i&(1<<j))
					prod*=f[ind][j];
			int sign=(k&1)?-1:1;
			if (!vis[ind]) ins(sign, prod);
			else remove(sign, prod);
		}
		vis[ind]^=1;
		cout << ans << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/