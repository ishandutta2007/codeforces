#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const db pi = acos(-1);
const db eps = 1e-7;
int n;
struct vec {
	db x, y; 
	vec (db xx = 0, db yy = 0) { x = xx, y = yy; }
	db len() { return sqrt(x * x + y * y); }
} f[N], g[N];
vec roundn(vec aa) { return vec(-aa.y, aa.x); }
vec operator + (vec aa, vec bb) { return vec(aa.x + bb.x, aa.y + bb.y); }
vec operator - (vec aa, vec bb) { return vec(aa.x - bb.x, aa.y - bb.y); }
vec operator * (vec aa, db bb) { return vec(aa.x * bb, aa.y * bb); }
vec operator / (vec aa, db bb) { return vec(aa.x / bb, aa.y / bb); }
db cro(vec aa, vec bb) { return aa.x * bb.y - aa.y * bb.x; }
vec inter(vec p1, vec v1, vec p2, vec v2) {
	db t = - cro(p1 - p2, v2) / cro(v1, v2);
	return v1 * t + p1;
}
vec circle(vec aa, vec bb, vec cc) {
	return inter((bb + aa) / 2, roundn(bb - aa), (cc + aa) / 2, roundn(cc - aa));
}
struct node {
	int x1, y1, x2, y2;
} d[N];
map< pii , int> mp;
ll ans = 0;
bool In(db x, db y, db Mid) {
	db l = min(x, y), r = max(x, y);
	return l <= Mid + 0.1 && Mid <= r + 0.1;
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) {
		scanf("%d%d%d%d", &d[i].x1, &d[i].y1, &d[i].x2, &d[i].y2);
		f[i] = vec(d[i].x1, d[i].y1);
		g[i] = vec(d[i].x2 - d[i].x1, d[i].y2 - d[i].y1);
		int len1 = abs(d[i].x2 - d[i].x1), len2 = abs(d[i].y2 - d[i].y1);
		int Gcd = __gcd(len1, len2);
		ans += Gcd + 1;
		mp.clear();
		L(j, 1, i - 1) {
			vec tmp = inter(f[i], g[i], f[j], g[j]);
			int p1 = floor(tmp.x + 0.2), p2 = floor(tmp.y + 0.2);
			if(fabs(tmp.x - p1) < eps && fabs(tmp.y - p2) < eps) {
				if(!In(d[i].x1, d[i].x2, tmp.x)) continue;
				if(!In(d[j].x1, d[j].x2, tmp.x)) continue;
				if(!In(d[i].y1, d[i].y2, tmp.y)) continue;
				if(!In(d[j].y1, d[j].y2, tmp.y)) continue;
				if(!mp[mkp(p1, p2)]) mp[mkp(p1, p2)] = 1, ans --;
			}
		}
	}
	cout << ans << endl;
	return 0;
}