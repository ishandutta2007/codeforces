#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 1e5 + 7;
int n, m, a[N], mp[N], dp[2][27][27];
char s[N];
void Min(int &x, int y) {
	if(x > y) x = y;
}
void Main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	L(i, 1, n) a[i] = s[i] - 'a';
	int bh = 1e7, ans = 0;
	L(i, 1, n) {
		if(i > 1 && a[i] == a[i - 1]) a[i] = ++bh, ans ++; 
		if(i > 2 && a[i] == a[i - 2]) a[i] = ++bh, ans ++;
	} 
	printf("%d\n", ans);
}
int main() {
	int T = read(); 
	while(T--) Main(); 
	return 0;
}