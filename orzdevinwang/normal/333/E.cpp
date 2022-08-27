// 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3007;
const int M = N * N / 2;
const db eps = 1e-7;
int n, m, X[N], Y[N], tot;
db dis(int x, int y) { return sqrt((X[x] - X[y]) * (X[x] - X[y]) + (Y[x] - Y[y]) * (Y[x] - Y[y])); }
bitset<N> bs[N];
pair<db, pii> f[M];
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d%d", &X[i], &Y[i]);
	L(i, 1, n) L(j, i + 1, n) f[++tot].first = dis(i, j), f[tot].second.first = i, f[tot].second.second = j;
	sort(f + 1, f + tot + 1);
	R(i, tot, 1) {
		if((bs[f[i].second.first] & bs[f[i].second.second]).count()) return printf("%.10lf\n", f[i].first / 2), 0;
		else bs[f[i].second.first].set(f[i].second.second), bs[f[i].second.second].set(f[i].second.first);  
	} 
	return 0;
}