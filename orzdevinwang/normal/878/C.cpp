#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
const int N = 5e4 + 7;
const int K = 20;
template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
	x *= f;
}
template<typename T> inline void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
int n, k;
struct node {
	int mx[K], mn[K], cnt;
} f[N];
bool operator < (node aa, node bb) {
	L(i, 1, k) if(aa.mx[i] > bb.mn[i]) return false;
	return true;
}
set< node > st;
int main() {
	read(n), read(k);
	L(i, 1, n) L(j, 1, k) read(f[i].mn[j]), f[i].mx[j] = f[i].mn[j], f[i].cnt = 1;
	L(i, 1, n) {
		while(st.size()) {
			auto now = st.find(f[i]);
			if(now == st.end()) break;
			f[i].cnt += now->cnt;
			L(j, 1, k) f[i].mx[j] = max(f[i].mx[j], now->mx[j]), f[i].mn[j] = min(f[i].mn[j], now->mn[j]);
			st.erase(now);
		}
		st.insert(f[i]);
		print((--st.end())->cnt), putsl;
	}
	return 0;
}