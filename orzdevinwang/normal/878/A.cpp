#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = (1 << 20);
int n, m, val, g[66][2], to[2], f[2];
char s[N];
int main() {
	scanf("%d", &n);
	L(i, 0, 9) g[i][0] = 0, g[i][1] = 1;
	while(n--) {
		scanf("%s", s + 1);
		scanf("%d", &val);
		R(i, 9, 0) {
			f[0] = g[i][0], f[1] = g[i][1];
			if(val >> i & 1) {
				if(s[1] == '|') to[0] = 1, to[1] = 1;
				if(s[1] == '&') to[0] = 0, to[1] = 1;
				if(s[1] == '^') to[0] = 1, to[1] = 0;
			}
			else {
				if(s[1] == '|') to[0] = 0, to[1] = 1;
				if(s[1] == '&') to[0] = 0, to[1] = 0;
				if(s[1] == '^') to[0] = 0, to[1] = 1;
			}
			g[i][0] = to[g[i][0]], g[i][1] = to[g[i][1]];
		}
	}
	int val1 = 0, val2 = 0, val3 = 0;
	L(i, 0, 9) {
		if( g[i][0] == 1 && g[i][1] == 1 ) val1 |= (1 << i);
		if(! (g[i][0] == 0 && g[i][1] == 0) ) val2 |= (1 << i);
		if( g[i][0] == 1 && g[i][1] == 0 ) val3 |= (1 << i);
	}
	puts("3");
	printf("| %d\n", val1);
	printf("& %d\n", val2);
	printf("^ %d\n", val3);
	return 0;
}