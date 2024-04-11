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
int n; 
ll m, x, sum;
void get(ll t) { 
	if((t & 3) == 0) sum ^= t;
	if((t & 3) == 1) sum ^= 1;
	if((t & 3) == 2) sum ^= t + 1;
}
int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%lld%lld", &x, &m);
		get(x - 1 + m), get(x - 1);
	}
	if(sum) return puts("tolik"), 0;
	puts("bolik");
	return 0;
}

// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111