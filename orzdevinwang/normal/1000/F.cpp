#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pil pair<int, lonf long>
#define mkp make_pair
using namespace std;
char buf[256],*p1=buf,*p2=buf,obuf[1<<24],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,256,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
void print(int x) {
    if(x>9) print(x/10);
    *O++=x%10+'0';
}
const int N = 5e5 + 7;
const int B = 1400;
int n, m, a[N], l = 1, r = 0, Ans[N], cnt[N];
queue<int> q;
struct asks {
	int l, r, id;
} f[N];
int main() {
	n = read();
	L(i, 1, n) a[i] = read();
	m = read();
	L(i, 1, m) f[i].l = read(), f[i].r = read(), f[i].id = i;
	sort(f + 1, f + m + 1, [&](asks aa, asks bb) {
		if(aa.l / B != bb.l / B) return aa.l < bb.l;
		if((aa.l / B) % 2 == 1) return aa.r < bb.r;
		else return aa.r > bb.r;
	});
	L(i, 1, m) {
		while(l > f[i].l) {
			--l, ++cnt[a[l]];
			if(cnt[a[l]] == 1) q.push(a[l]);
		}
		while(r < f[i].r) {
			++r, ++cnt[a[r]];
			if(cnt[a[r]] == 1) q.push(a[r]);
		}
		while(l < f[i].l) {
			--cnt[a[l]];
			if(cnt[a[l]] == 1) q.push(a[l]);
			++l;
		}
		while(r > f[i].r) {
			--cnt[a[r]];
			if(cnt[a[r]] == 1) q.push(a[r]);
			--r;
		}
		while(!q.empty() && cnt[q.front()] != 1) q.pop();
		if(q.size() > 1000000) {
			while(!q.empty()) q.pop();
			L(j, l, r) if(cnt[a[j]] == 1) q.push(a[j]);
		}
		if(!q.empty()) Ans[f[i].id] = q.front();
	}
	L(i, 1, m) print(Ans[i]), *O++ = '\n';
	fwrite(obuf,O-obuf,1,stdout);
	return 0;
}