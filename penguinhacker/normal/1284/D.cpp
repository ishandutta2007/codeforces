#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000, MOD=1e9+9;
int n, ans1[mxN], ans2[mxN], pp[mxN];
ar<int, 3> e1[2*mxN], e2[2*mxN];

void solve(ar<int, 3> e[], int res[]) {
	int sum1=0, sum2=0;
	for (int i=0; i<2*n; ++i) {
		int type=e[i][1], ind=e[i][2];
		if (type==0) {
			res[ind]-=sum2;
			sum1=(sum1+pp[ind])%MOD;
		}
		if (type==1) {
			res[ind]=(res[ind]+sum1+MOD)%MOD;
			sum2=(sum2+pp[ind])%MOD;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		e1[2*i]={a, 0, i};
		e1[2*i+1]={b, 1, i};
		e2[2*i]={c, 0, i};
		e2[2*i+1]={d, 1, i};
		pp[i]=i==0?1:2*pp[i-1]%MOD;
	}
	sort(e1, e1+2*n);
	sort(e2, e2+2*n);
	solve(e1, ans1);
	solve(e2, ans2);
	bool b=1;
	for (int i=0; i<n; ++i)
		b&=ans1[i]==ans2[i];
	cout << (b?"YES":"NO") << "\n";
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/