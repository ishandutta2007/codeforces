#include<bits/stdc++.h>

using namespace std;
#define ll long long

int T, n;
ll a, b;
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n), a=b=0;
		for(int i=1, x; i<=n; ++i) scanf("%d", &x), a+=x, b^=x;
		printf("2\n%lld %lld\n", b, a+b);
	}
	return 0;
}