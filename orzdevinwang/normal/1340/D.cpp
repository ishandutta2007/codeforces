#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3e5 + 7; 
vi e[N];
vector < pair < int, int > > S;
void ret (int x, int y) {
	S.push_back(make_pair (x, y));
}
int n;
void dfs (int x, int fa, int inp) {
//	cout << x << "\n";
	ret (x, inp);
	int deg = 0;
	for (int v : e[x]) if(v != fa) deg += 1;
	int now = 0;
	if(inp > deg) {
		now = inp - deg - 1, ret (x, now);
		for (int v : e[x]) if(v != fa) 
			now += 1, dfs (v, x, now), ret (x, now);
	}
	else if(inp == 0) {
		for (int v : e[x]) if(v != fa) now += 1, dfs (v, x, now), ret (x, now);
		now = -1;
	}
	else {
		now = inp;
		if(now == deg + 1) now = 0, ret (x, now);
		for (int v : e[x]) if(v != fa) {
			now += 1, dfs (v, x, now), ret (x, now);
			if(now == deg + 1) now = 0, ret (x, now);
		}
	}
	assert (now + 1 == inp);
} 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	dfs (1, -1, 0);
	cout << sz(S) << "\n";
	for (auto x : S) cout << x.first << ' ' << x.second << '\n';
	return 0;
}