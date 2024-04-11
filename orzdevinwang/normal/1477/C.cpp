#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
const db eps = 1e-5;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f; 
}
int n, m, p[N];
struct vec {
	db x, y; 
	vec (db xx = 0, db yy = 0) { x = xx, y = yy; }
	db len() { return sqrt(x * x + y * y); }
} f[N], now;
vec roundn(vec aa) { return vec(-aa.y, aa.x); }
vec operator + (vec aa, vec bb) { return vec(aa.x + bb.x, aa.y + bb.y); }
vec operator - (vec aa, vec bb) { return vec(aa.x - bb.x, aa.y - bb.y); }
vec operator * (vec aa, db bb) { return vec(aa.x * bb, aa.y * bb); }
vec operator / (vec aa, db bb) { return vec(aa.x / bb, aa.y / bb); }
db dot(vec aa, vec bb) { return aa.x * bb.x + aa.y * bb.y; }
int main() {
	n = read();
	L(i, 1, n) {
		f[i].x = read(), f[i].y = read();
		p[i] = i;
		int k = 5;
		while(k --) {
			int now = i;
			while(now > 2 && dot(f[p[now]] - f[p[now - 1]], f[p[now - 1]] - f[p[now - 2]]) >= 0) swap(p[now], p[now - 1]), --now;
		}
	}
	L(i, 1, n) printf("%d ", p[i]);
	puts("");
	return 0;
}