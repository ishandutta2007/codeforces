#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
int T, n, x;
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &x);
		L(i, 1, 1000) {
			n -= (i == 1 ? 2 : x);
			if(n <= 0) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}