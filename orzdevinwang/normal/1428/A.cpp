#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e5 + 7;
int T, n, m, a, b, c, d; 
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a == c || b == d) printf("%d\n", abs(a - c) + abs(b - d));
		else printf("%d\n", abs(a - c) + abs(b - d) + 2);
	}
	return 0;
}