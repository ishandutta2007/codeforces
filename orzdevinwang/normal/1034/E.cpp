#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db long double
#define mp make_pair
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
const int M = 2.2e6;
int n, m, cnt[M];
void fwtor(ull *f, int len) {
    for(int i = 2; i <= len; i <<= 1) 
        for(int l = (i >> 1), j = 0; j < len; j += i) 
            for(int k = j; k < j + l; k++) 
                f[k + l] += f[k];
}
void fwtior(ull *f, int len) {
    for(int i = 2; i <= len; i <<= 1) 
        for(int l = (i >> 1), j = 0; j < len; j += i) 
            for(int k = j; k < j + l; k++) 
                f[k + l] -= f[k];
}
ull a[M], b[M];
char ch;
int main() {
    n = read(), m = (1 << n);
    for(int i = 1; i < m; i++) cnt[i] = cnt[i >> 1] + (i & 1);
    for(int i = 0; i < m; i++) {
        ch = getchar(); while(ch < '0' || ch > '3') ch = getchar(); 
        a[i] = (1LL << (cnt[i] * 2)) * (ch - '0');
    }
    for(int i = 0; i < m; i++) {
        ch = getchar(); while(ch < '0' || ch > '3') ch = getchar();
        b[i] = (1LL << (cnt[i] * 2)) * (ch - '0');
    }
    fwtor(a, m), fwtor(b, m);
    for(int i = 0; i < m; i++) a[i] *= b[i];
    fwtior(a, m);
    for(int i = 0; i < m; i++) *O++ = (a[i] >> (cnt[i] * 2) & 3) + '0';
    *O++ = '\n';
    fwrite(obuf,O-obuf,1,stdout);
    return 0;
}