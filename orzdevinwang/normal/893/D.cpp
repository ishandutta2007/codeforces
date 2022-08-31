#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define int long long
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
signed main() {
	n = read(), d = read();
	int now = 0, mx = d, ans = 0;
	L(i, 1, n) {
		a[i] = read();
		if(a[i] > 0) {
			now += a[i], mx = max(mx, now);
			if(now > d) return puts("-1"), 0;
		}
		else if(a[i] == 0 && now < 0) {
			int val = -now;
			mx += val;
			if(mx > d) ans ++, mx = 0;
			now = 0;
		}
		else if(a[i] < 0) now += a[i];
	}
	cout << ans << endl;
	return 0;
}