#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
const int N = 1e5 + 7;
int n, a[N];
int main() {
	scanf("%d", &n);
	ll sum = 0;
	L(i, 1, n) scanf("%d", &a[i]), sum += a[i];
	sort(a + 1, a + n + 1);
	printf("%lld\n", max((sum + n - 2) / (n - 1), (ll)a[n]));
	return 0;
}