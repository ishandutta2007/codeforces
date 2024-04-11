#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, a[N], ans[N], Can = 30, now;
int G[33], D[33];
void ins(int x) {
	int qwq = x;
	R(i, 30, 0) if((x >> i) & 1) {
		if(!G[i]) D[i] = qwq, G[i] = x;
		x ^= G[i];
	}
}
void work(int k) {
	if(k == -1) return printf("%d ", now), void();
	work(k - 1);
	now ^= D[k];
	work(k - 1);
}
void INS() {
	L(i, 0, 30) D[i] = G[i] = 0;
	L(i, 1, n) if(a[i] < (1 << Can)) ins(a[i]); 
	L(i, 0, 30) if(!G[i]) {
		Can = i;
		break;
	}
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	int las = 114514;
	while(Can != las) {
		las = Can;
		INS();
	}
	printf("%d\n", Can);
	work(Can - 1);
	puts("");
	return 0;
}