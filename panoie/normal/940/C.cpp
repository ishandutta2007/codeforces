#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
using namespace std;
#define ll long long
#define rt register int
#define Rep(i,x,y) for(rt i=(x);i<(y);++i)
#define per(i,x,y) for(rt i=(x);i>=(y);--i)
#define rep(i,x,y) for(rt i=(x);i<=(y);++i)
#define travel(i,x) for(rt i=h[x];i;i=pre[i])
const int N = 100005;
int n, k, cnt, a[N], b[N], c[N];
char s[N], t[N];
int main() {
	scanf("%d%d%s", &n, &k, s);
	strcpy(t, s);
	sort(t, t+n);
	Rep(i, 0, n) if(!a[t[i]]) a[t[i]]=++cnt, b[cnt]=t[i];
	if(k>n){
		printf("%s", s);
		rep(i, n+1, k) putchar(b[1]);
		return 0;
	}
	Rep(i, 0, k) c[i]=a[s[i]];
	++c[k-1];
	per(i, k-1, 0) if(c[i]>cnt) c[i]-=cnt, c[i-1]++; else break;
	Rep(i, 0, k) putchar(b[c[i]]);
	return 0;
}