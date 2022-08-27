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
int n, d;
int a[N];
void Main() {
	n = read();
	int cnt = 0;
	L(i, 1, n) a[i] = read(), cnt += (a[i] == 1);
	if(cnt) {
		printf("%d\n", n - cnt);
		return;
	}
	int ans = 1e9;
	L(i, 1, n) {
		int now = 0;
		L(j, i, n) {
			now = __gcd(now, a[j]);
			if(now == 1) {
				ans = min(ans, j - i);
				break;
			}
		}
	}
	if(ans == 1e9) puts("-1");
	else printf("%d\n", ans + n - 1);
}
int main() {
	Main();
	return 0;
}