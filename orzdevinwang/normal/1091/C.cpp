#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, f[N];
void work(int x) {
	// x 
	int t = (n / x);
	printf("%lld ", x + 1ll * x * t * (x - 1) / 2);
}
void Main() {
	scanf("%d", &n);
	L(i, 1, sqrt(n)) {
		if(n % i == 0) {
			work(i);
			
		}
	}
	R(i, sqrt(n), 1) if(n % i == 0) (n / i != i) && (work(n / i), 0);
	puts("");
}
int main() {
	Main();
	return 0;
}