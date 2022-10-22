#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxK=5000, M=998244353;
int n, m, k, C[mxK+1][mxK+1], p[mxK+1], ans;

int add(int a, int b) { if ((a+=b)>=M) a-=M; return a; }
int sub(int a, int b) { if ((a-=b)<0) a+=M; return a; }
int mul(int a, int b) { return (ll)a*b%M; }
int bp(int b, int p=M-2) {
	int r=1;
	for (; p; p/=2, b=mul(b, b))
		if (p%2)
			r=mul(r, b);
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i=0; i<=k; ++i)
		C[i][0]=1;
	for (int i=1; i<=k; ++i) {
		p[i]=bp(i, k);
		for (int j=1; j<=i; ++j)
			C[i][j]=add(C[i-1][j-1], C[i-1][j]);
	}
	int b=1;
	for (int i=1; i<=min({n, k}); ++i) {
		b=mul(mul(b, bp(m)), mul(n-i+1, bp(i)));
		int cur=0, s=1;
		for (int j=i; j; --j) {
			cur=add(cur, mul(s, mul(C[i][j], p[j])));
			s=sub(M, s);
		}
		ans=add(ans, mul(b, cur));
	}
	cout << ans;
	return 0;
}