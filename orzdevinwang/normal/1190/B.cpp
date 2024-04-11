#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, a[N], cnt = 0;
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if(a[n] == 0) return puts("cslnb"), 0;
	L(i, 1, n - 1) if(a[i] == a[i + 1] && !cnt && a[i]) a[i] --, cnt = 1;
	L(i, 1, n - 1) if(a[i] == a[i + 1]) return puts("cslnb"), 0;
	L(i, 1, n) cnt ^= ((a[i] - (i - 1)) & 1);
	if(cnt & 1) return puts("sjfnb"), 0;
	else return puts("cslnb"), 0;
	return 0;
}