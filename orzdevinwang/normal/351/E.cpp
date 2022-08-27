// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
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
int n, f[N], cnta[N], cntb[N];
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &f[i]), f[i] = abs(f[i]);
	L(i, 1, n) L(j, 1, i - 1) {
		if(f[i] > f[j]) cntb[i] ++;
		if(f[i] < f[j]) cnta[j] ++;
	}
	int sum = 0;
	L(i, 1, n) sum += min(cnta[i], cntb[i]);
	printf("%d\n", sum);
	return 0;
}