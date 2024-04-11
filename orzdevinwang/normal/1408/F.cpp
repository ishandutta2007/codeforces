#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 15005;
const int M = 4e6;
int n, pp, q[M][2], cnt;
void dis(int k) {
	for(int i = 2; i <= n; i <<= 1) {
		int l = (i >> 1);
		for(int j = 1; j <= pp; j += i)  
			L(d, j, j + l - 1) {
				++cnt;
				q[cnt][0] = (d + k - 1) % n + 1;
				q[cnt][1] = (d + l + k - 1) % n + 1;
			}
	}
}
int main() {
	scanf("%d", &n);
	pp = 1;
	while(pp * 2 <= n) pp <<= 1;
	dis(0), dis(pp); 
	printf("%d\n", cnt);
	L(i, 1, cnt) printf("%d %d\n", q[i][0], q[i][1]);
	return 0;
}