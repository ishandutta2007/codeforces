#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pll pair<ll, ll> 
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int V = 7777;
bitset< V > Mu[V], B[V], S[N];
int tot, p[V], mu[V];
bool Prime[N];
void xxs(int x) {
	mu[1] = 1;
	L(i, 2, x) {
		if(!Prime[i]) p[++tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && p[j] * i <= x; j ++) {
			Prime[p[j] * i] = 1;
			if(i % p[j] == 0) {
				mu[p[j] * i] = 0;
				break;
			}
			mu[p[j] * i] = -mu[i];
		}
	}
	L(i, 1, x) L(j, 1, x / i) if(mu[j]) Mu[i].set(i * j);
	L(i, 1, x) L(j, 1, x / i) B[i * j].set(i);
}
int n, q;
int main() {
	xxs(7000);
	scanf("%d%d", &n, &q);
	while(q--) {
		int opt, x, y, z; scanf("%d%d%d", &opt, &x, &y);
		if(opt == 1) S[x] = B[y];
		if(opt == 2) scanf("%d", &z), S[x] = (S[y] ^ S[z]);
		if(opt == 3) scanf("%d", &z), S[x] = (S[y] & S[z]);
		if(opt == 4) printf("%d", ((S[x] & Mu[y]).count()) & 1);
	}
	puts("");
	return 0;
}