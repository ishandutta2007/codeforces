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

ll gcd(ll x ,  ll y) {
	if(y == 0) return x;
	return gcd(y , x % y);
}

const int N = 1e5 + 10;

int T, n, a[N];
int lst[N], nxt[N];
queue <int> q;
int Ans[N], cnt = 0;

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i < n; i++) nxt[i] = i + 1;
		nxt[n] = 1;
		for (int i = 1; i < n; i++)
			if (gcd(a[i], a[i + 1]) == 1)
				q.push(i);
		if (gcd(a[n], a[1]) == 1) q.push(n);
		cnt = 0;
		while (!q.empty()) {
			int t = q.front(); q.pop();
			Ans[++cnt] = nxt[t];
			if (t == nxt[t]) break;
			if (q.size() && q.front() == nxt[t]) q.pop(); 
			nxt[t] = nxt[nxt[t]];
			if (gcd(a[t], a[nxt[t]]) == 1)
				q.push(t);
		}
		print(cnt, ' ');
		for (int i = 1; i <= cnt; i++)
			print(Ans[i], ' ');
		puts("");
	}
	return 0;
}