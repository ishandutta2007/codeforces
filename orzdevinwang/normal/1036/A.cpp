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
ll n, k;
void Main() {
	scanf("%lld%lld", &n, &k);
	printf("%lld\n", (k + n - 1) / n);
}
int main() {
	Main();
	return 0;
}