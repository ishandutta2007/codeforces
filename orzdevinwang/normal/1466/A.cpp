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
const int N = 1e6 + 7;
int n, m, a[N], mp[N];
void Main() {
	int ans = 0;
	n = read();
	L(i, 1, n) a[i] = read();
	sort(a + 1, a + n + 1);
	L(i, 0, 100) mp[i] = 0; 
	L(i, 1, n) L(j, i + 1, n) {
		if(!mp[a[j] - a[i]]) mp[a[j] - a[i]] = 1, ans ++;
	}
	printf("%d\n", ans);
}
int main() {
	int T = read(); 
	while(T--) Main(); 
	return 0;
}