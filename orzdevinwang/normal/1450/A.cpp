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
int n, m, x[N], y[N];
char s[N];
void Main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	L(i, 0, 25) L(j, 1, n) if(s[j] - 'a' == i) putchar(s[j]);
	puts("");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}