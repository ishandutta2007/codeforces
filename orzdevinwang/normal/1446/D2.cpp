#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
char buf[256],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,256,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch=='-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f;
}
const int N = 2e5 + 7;
const int B = 233;
int n, a[N], cnt[N], zs, ans;
int fir[N << 1];
int max(int x, int y) { return x > y ? x : y; }
void worka(int x) {
	int now = N;
	memset(fir, -1, sizeof(fir));
	fir[now] = 0;
	L(i, 1, n) {
		if(a[i] == zs) now ++;
		else if(a[i] == x) now --;
		if(!~fir[now]) fir[now] = i;
		else ans = max(ans, i - fir[now]);
	}
}
int lef[N], rig[N], f[N], fg[N];
vector<int> ve[N];
void workb(int x) {
	L(i, 1, cnt[x]) {
		fill(fir + N - cnt[x] - 2, fir + N + cnt[x] * 2 + 3, -1);
		int tot = 0, las = (i == 1 ? 0 : ve[x][i - 2]), now = ve[x][i - 1], len = 0;
		while(lef[now - 1] > las && len <= cnt[x]) now = lef[now - 1], ++len, f[++tot] = now;
		int dd = i, KK = N;
		if(!lef[now - 1] && i == 1) fir[N] = 0;
		reverse(f + 1, f + tot + 1);
		f[++tot] = ve[x][i - 1], fg[tot] = 1;
		now = ve[x][i - 1], len = 0;
		while(rig[now + 1] && len <= cnt[x]) {
			now = rig[now + 1];
			while(dd < cnt[x] && ve[x][dd] < now) f[++tot] = ve[x][dd], fg[tot] = 1, ++ dd;
			++len, f[++tot] = now;
		}
		if(len <= cnt[x]) while(dd < cnt[x]) f[++tot] = ve[x][dd], fg[tot] = 1, ++ dd;
		f[tot + 1] = n + 1;
		if(rig[now + 1]) f[tot + 1] = rig[now + 1];
		L(j, 1, tot) {
			if(fg[j] == 1) -- KK, fg[j] = 0; else ++ KK;
			if(!~fir[KK]) fir[KK] = f[j];
			else ans = max(ans, f[j + 1] - 1 - fir[KK]); 
		}
	}
}
int main() {
	n = read(); 
	L(i, 1, n) a[i] = read(), cnt[a[i]] ++;
	L(i, 1, n) if(cnt[i] > cnt[zs]) zs = i;
	L(i, 1, n) if(a[i] == zs) lef[i] = rig[i] = i;
	L(i, 1, n) if(!lef[i]) lef[i] = lef[i - 1];
	R(i, n, 1) if(!rig[i]) rig[i] = rig[i + 1];
	L(i, 1, n) if(cnt[a[i]] <= B) ve[a[i]].push_back(i);
	L(i, 1, n) if(i != zs) {
		if(cnt[i] > B) worka(i); 
		else workb(i);
	}
	printf("%d\n", ans);
	return 0;
}