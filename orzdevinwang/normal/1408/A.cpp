#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 1e5 + 7;
int T, n, a[N], b[N], c[N];
void init() {
	
} 
void work() {
	
}
int p[N];
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		L(i, 1, n) scanf("%d", &a[i]);
		L(i, 1, n) scanf("%d", &b[i]);
		L(i, 1, n) scanf("%d", &c[i]);
		L(i, 1, n) {
			if(a[i] != p[i - 1] && a[i] != p[i % n + 1]) {
				p[i] = a[i];
				continue;
			}
			if(b[i] != p[i - 1] && b[i] != p[i % n + 1]) {
				p[i] = b[i];
				continue;
			}
			if(c[i] != p[i - 1] && c[i] != p[i % n + 1]) {
				p[i] = c[i];
				continue;
			}
		} 
		L(i, 1, n) printf("%d ", p[i]);
		puts("");
	}
	return 0;
}