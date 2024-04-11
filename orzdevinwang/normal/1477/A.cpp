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
inline ll read() {
	ll x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f; 
}
int n;
ll k, f[N];
void Main() {
	n = read(), k = read();	
	ll res = 0;
	L(i, 1, n) f[i] = read();
	sort(f + 1, f + n + 1);
	L(i, 2, n) res = __gcd(res, f[i] - f[1]);
	k -= f[1];
	if(k % res == 0) puts("YES");
	else puts("NO");
}
int main() {
	int T = read();
	while(T--) Main(); 
	return 0;
}