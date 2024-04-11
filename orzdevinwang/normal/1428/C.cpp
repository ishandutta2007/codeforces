#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e6 + 7;
int T, n, tot;
char s[N], g[N];
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		n = strlen(s);
		tot = 0;
		g[0] = '?';
		L(i, 0, n - 1) {
			if(s[i] == 'A') g[++tot] = 'A';
			else {
				if(g[tot] == 'A') --tot;
				else if(g[tot] == 'B') --tot;
				else g[++tot] = 'B';
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}