#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 1e5 + 7;
int T, n, v, a[N];
int main() {
	scanf("%d", &T);
	while(T--) {
		int sum = 0, flag = 1, ff = 0;
		scanf("%d%d", &n, &v);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i], flag &= (a[i] == v), ff |= (a[i] == v);
		if(flag) printf("0\n");
		else if(sum == v * n || ff) printf("1\n");
		else printf("2\n");
	}
	return 0;
}