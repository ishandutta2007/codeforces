#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e3 + 7;
int T; 
int main() {
	scanf("%d", &T);
	while(T--) {
		int x; scanf("%d", &x);
		if(x == 1) puts("0");
		else if(x == 2) puts("1");
		else if(x % 2 == 0 || x == 3) puts("2");
		else puts("3");
	}
	return 0;
}