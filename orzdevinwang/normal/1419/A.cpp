#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 1e5 + 7;
int T, n;
char a[N];
int did(int x) { /// laz  odd 
	if(x == 1) {
		for(int i = 1; i <= n; i += 2) 
			if((a[i] - '0') % 2 == 1) return 1;
		return 2;
	}
	else {
		for(int i = 2; i <= n; i += 2) 
			if((a[i] - '0') % 2 == 0) return 2;
		return 1;
	}
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		scanf("%s", a + 1);
		printf("%d\n", did(n % 2));
	}
	return 0;
}