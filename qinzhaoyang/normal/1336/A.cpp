#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

priority_queue <int> q;

vector <int> G[N];
int siz[N], dep[N], n, k;
ll ans;

void dfs(int x, int fa) {
	siz[x] = 1;
	for (int v : G[x]) if (v != fa) {
		dep[v] = dep[x] + 1;
		dfs(v, x), siz[x] += siz[v];
	}
	q.push(dep[x] - (siz[x] - 1));
}

int main() {
	read(n), read(k);
	for (int i = 1; i < n; i++) {
		int a, b; read(a), read(b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 0; i < k; i++)
		ans += q.top(), q.pop();
	print(ans, '\n');
	return 0;
}