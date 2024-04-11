#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e6 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f; 
}
int n, d, f[N], ans;
bool F[N];
void Main() {
	n = read();
	L(i, 1, 10) F[(1 << (i - 1)) * ((1 << i) - 1)] = 1;
	L(i, 1, n) {
		if(n % i == 0 && F[i]) ans = max(ans, i);
	}
	printf("%d\n", ans);
}
int main() {
	Main();
	return 0;
}