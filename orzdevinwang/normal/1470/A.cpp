#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 1e6 + 7;
int n, m, c[N], k[N], cnt[N];
int f[N]; 
void Main() {
	n = read(), m = read();
	L(i, 1, m) cnt[i] = 0;
	L(i, 1, n) k[i] = read(), cnt[k[i]] ++;
	ll ans = 0;
	L(i, 1, m) c[i] = read();
	queue<int> q;
	R(i, m, 1) L(j, 1, cnt[i]) q.push(i);
	L(i, 1, m) {
		ans += (ll) cnt[i] * c[i];
		cnt[i] = 0;
		if(q.empty() || cnt[q.front()] == 0) continue;
		cnt[q.front()] --;
		ans += c[i];
		q.pop();
	}
	printf("%lld\n", ans);
}
int main() {
	int T = read(); while(T--) Main();
	return 0;
}