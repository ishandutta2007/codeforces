#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 9;
int T, n, m, a[N], b[N], minn, gcdd;
int gcd(int x, int y) {
	if(x == 0 || y == 0) return 0;
	return __gcd(x, y);
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		minn = 1;
		for(int i = 2; i <= n; i++) if(a[i] > a[minn]) minn = i;
		b[1] = a[minn], gcdd = a[minn], a[minn] = 0;
		for(int i = 2; i <= n; i++) {
			minn = 0;
			for(int j = 1; j <= n; j++) 
				if(gcd(gcdd, a[j]) > gcd(gcdd, a[minn])) 
					minn = j;
			b[i] = a[minn], gcdd = gcd(a[minn], gcdd), a[minn] = 0;
		}
		for(int i = 1; i <= n; i++) printf("%d ", b[i]);
		puts("");
	}
	return 0;
}