#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 1e5 + 7;
const int Ma = 100;
int T, n, m, a[N];
void init() {
	
} 
void work() {
	
}
int p[N];
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		a[0] = -1;
		L(i, 1, n) {
			scanf("%d", &a[i]);
			ans += (a[i] != a[i - 1]);
		}
		ans --, m--; // ans , m: change 
		if(m == 0) {
			if(ans == 0) printf("1\n");
			else printf("-1\n");
		}
		else {
			if(ans == 0) printf("1\n"); 
			else printf("%d\n", (ans + m - 1) / m);
		}
	}
	return 0;
}