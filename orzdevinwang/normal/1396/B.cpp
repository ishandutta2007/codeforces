#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 1e5 + 7;
int T, n, a[N], sum;
int main() {
	scanf("%d", &T);
	while(T--) {
		sum = 0;
		scanf("%d", &n);
		L(i, 1, n) scanf("%d", &a[i]), sum += a[i];
		sort(a + 1, a + n + 1);
		if(a[n] > sum - a[n]) printf("T\n");
		else printf("%s\n", sum % 2 == 1 ? "T" : "HL");
	}
	return 0;
}