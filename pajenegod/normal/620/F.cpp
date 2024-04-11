// Testing submitting versions of https://codeforces.com/contest/620/submission/72790198
#include "bits/stdc++.h"
using ll = long long;
using namespace std;
																																																																																																	#pragma GCC target("avx,avx2,fma")
const int N = 5e4 + 1, M = 1e6 + 1;																																																																																								void read(int&n){n=0;while(1){char c=getchar();if(c==' '||c=='\n')break;n=(n<<1)+(n<<3)+c-'0';}}void read(ll&n){n=0;while(1){char c=getchar();if(c==' '||c=='\n')break;n=(n<<1)+(n<<3)+c-'0';}}void write(int n){if(n>9)write(n/10),putchar(n%10+'0');else putchar(n+'0');}void write(ll n){if(n>9)write(n/10),putchar(n%10+'0');else putchar(n+'0');}
 
int n, m, a[N], l[N], r[N], mx[N], ans[N], p[M];
 
int main() { cin.tie(0)->sync_with_stdio(0);
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	for (int i = 1; i < M; i++) {
		p[i] = p[i - 1] ^ i;
	}
	for (int i = 1; i <= m; i++) {
		read(l[i]), read(r[i]);
	}
	for (int i = 1; i <= n; i++) {
		mx[i] = a[i];
		for (int j = i - 1; j >= 1; j--) {
			mx[j] = mx[j + 1];
			if (a[j] <= a[i]) {
				mx[j] = max(mx[j], p[a[j] - 1] ^ p[a[i]]);
			} else {
				mx[j] = max(mx[j], p[a[i] - 1] ^ p[a[j]]);
			}
		}
		for (int j = 1; j <= m; j++) {
			if (l[j] <= i && i <= r[j]) {
				ans[j] = max(ans[j], mx[l[j]]);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		write(ans[i]), putchar('\n');
	}
}