// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 2e5 + 7;
const int M = (1 << 19) + 10;
const db pi = acos(-1);
struct CP {
	db x, y; 
	CP (double aa = 0, double bb = 0) {
		x = aa, y = bb;
	}
} ;
CP operator + (CP aa, CP bb) {
	return CP(aa.x + bb.x, aa.y + bb.y);
}
CP operator - (CP aa, CP bb) {
	return CP(aa.x - bb.x, aa.y - bb.y);
}
CP operator * (CP aa, CP bb) {
	return CP(aa.x * bb.x - aa.y * bb.y, aa.x * bb.y + aa.y * bb.x);
}
priority_queue< pair<int, int> > q;
struct Poly {
	vector<int> a; 
} f[N];
int n, m, K, pp[M], tot;
void fft(CP *f, int len, int flag) {
	for(int i = 0; i < len; ++i) if(pp[i] < i) swap(f[pp[i]], f[i]); 
	for(int i = 2; i <= len; i <<= 1) {
		CP ch(cos(2 * pi / i), flag * sin(2 * pi / i));
		for(int l = (i >> 1), j = 0; j < len; j += i) {
			CP now(1, 0);
			for(int k = j; k < j + l; ++k) {
				CP ga = f[k], gb = f[k + l] * now;
				f[k] = ga + gb, f[k + l] = ga - gb, now = now * ch;
			}
		}
	}
	if(flag == -1) for(int i = 0; i < len; i++) f[i].x /= len;
}
CP a[M], b[M];
int cnt[N], p[N];
int main() {
	scanf("%d%d%d", &n, &m, &K);
	L(i, 1, n) scanf("%d", &p[i]), cnt[p[i]] ++;
	L(i, 1, m) {
		++tot;
		L(j, 0, cnt[i]) f[tot].a.push_back(1);
		q.push(make_pair(-cnt[i], tot));
	}
	while(q.size() != 1) {
		int sa = q.top().second;
		q.pop();
		int sb = q.top().second;
		q.pop();
		vector<int> tmpa, tmpb;
		int la = f[sa].a.size(), lb = f[sb].a.size();
		L(i, 0, f[sa].a.size() - 1) a[i] = f[sa].a[i];
		swap(tmpa, f[sa].a);
		L(i, 0, f[sb].a.size() - 1) b[i] = f[sb].a[i];
		swap(tmpb, f[sb].a);
		int lc = la + lb - 1;
		for(; lc != (lc & -lc); lc += (lc & -lc));
		if(lc > M) assert(0);
		for(int i = 0; i < lc; ++i) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lc >> 1)));
		fft(a, lc, 1), fft(b, lc, 1);
		for(int i = 0; i < lc; ++i) a[i] = a[i] * b[i];
		fft(a, lc, -1); 
		for(int i = 0; i < la + lb - 1; ++i) f[sa].a.push_back((ll)(a[i].x + 0.49) % 1009);
		for(int i = 0; i < lc; ++i) a[i].x = b[i].x = a[i].y = b[i].y = 0;
		q.push(make_pair(-f[sa].a.size(), sa));
	}
	int pp = q.top().second, mm = 0;
	printf("%d\n", f[pp].a[K]);
	return 0;
}