#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 7;
int T;
ll A, B;
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &A, &B);
		ll now = 9, Ans = 0;
		while(now <= B) {
			Ans += A;
			now = now * 10 + 9;
		}
		printf("%lld\n", Ans);
	}
	return 0;
}