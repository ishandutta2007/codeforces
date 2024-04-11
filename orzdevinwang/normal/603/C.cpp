#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
int n, m, k, now;
int SGa(int x) {
	// if(x == 0) return 0;
	// if(x == 1) return 1;
	// if(x % 2 == 1) return 0;
	// if(SGa(x - 1) == 1) return 2;
	// else return 1; 
	if(x == 0) return 0;
	if(x == 1) return 1;
	if(x == 2) return 2;
	if(x % 2) return 0;
	else return 1;
}
// int mp[114514];
// int SGb(int x) {
// 	if(x == 0) return 0;
// 	if(x == 1) return 1;
// 	if(mp[x] != -1) return mp[x];
// 	if(x % 2 == 1) {
// 		if(SGb(x - 1) == 0) return 1;
// 		else return 0;
// 	}
// 	int A = SGb(x - 1), B = SGb(x / 2);
// 	if(A && B) return 0;
// 	if(A == 1 || B == 1) return 2;
// 	return 1;
// }
int SGb(int x) {
	if(x == 0) return 0;
	if(x == 1 || x == 3) return 1;
	if(x % 2 == 1) return 0;
	int A = SGb(x - 1), B = SGb(x / 2);
	if(A && B) return 0;
	if(A == 1 || B == 1) return 2;
	return 1;
}
int main() {
	// memset(mp, -1, sizeof(mp));
	// L(i, 1, 100) cout << SGb(i) << " ";
	// puts("");
	// L(i, 1, 100) cout << SGa(i) << " ";
	// puts("");
	scanf("%d%d", &m, &k);
	while(m--) {
		scanf("%d", &n);
		if(k % 2 == 0) now ^= SGa(n);
		else now ^= SGb(n);
	}
	if(now == 0) puts("Nicky");
	else puts("Kevin");
	return 0;
}