#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e6 + 7;
int T, n, can[N];
char s[N];
int main() {
	scanf("%d", &T);
	while(T--) {
		int ans = 0;
		bool flaga = 1, flagb = 1;
		scanf("%d%s", &n, s);
		L(i, 0, n - 1) if(s[i] != '-') {
			if(s[i] == '>') flaga = 0;
			if(s[i] == '<') flagb = 0;
		}
		if(flaga || flagb) printf("%d\n", n);
		else {
			L(i, 0, n - 1) if(s[i] == '-' || s[(i + 1) % n] == '-') ans++;
			printf("%d\n", ans);
		}
	}
	return 0;
}