#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int n, a[mxN], pos=-1, p[mxN+1], p2[mxN+1];
ll f[mxN+1], iF[mxN+1], iv[mxN+1];
vector<ar<int, 2>> v;

ll C(int x, int y) {
	return f[x]*iF[y]%M*iF[x-y]%M;
}

ll solve(int l, int r) {
	if (l<0||r>=n||p[r+1]-p[l]>0)
		return 0;
	ll res=1;
	for (ar<int, 2> x : v) {
		int cl=r-l+1;
		if (l<=x[1]&&x[1]<=r)
			return 0;
		int ex=x[0]-cl;
		if (x[1]<l) {
			int ls=l-x[1];
			if (ls>ex||r+ex-ls>=n)
				return 0;
			res=res*C(ex-1, ls-1)%M;
			l-=ls, r+=ex-ls;
		} else {
			int rs=x[1]-r;
			if (rs>ex||l-(ex-rs)<0)
				return 0;
			res=res*C(ex-1, rs-1)%M;
			l-=ex-rs, r+=rs;
		}
	}
	//cout << l << " " << r << " " << l+n-1-r << " " << C(l+n-1-r, l) << endl;
	return res*C(l+n-1-r, l)%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=p2[0]=1;
	p2[1]=2;
	for (int i=2; i<=mxN; ++i) {
		p2[i]=p2[i-1]*2%M;
		f[i]=i*f[i-1]%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iv[i]*iF[i-1]%M;
	}
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (a[i]&&(pos==-1||a[i]<a[pos]))
			pos=i;
		p[i+1]=p[i];
		if (a[i]>1) {
			v.push_back({a[i], i});
			++p[i+1];
		}
	}
	sort(v.begin(), v.end());
	if (pos==-1) {
		cout << p2[n-1];
	} else if (a[pos]==1) {
		cout << solve(pos, pos);
	} else
		cout << p2[a[pos]-2]*(solve(pos-a[pos]+1, pos-1)+solve(pos+1, pos+a[pos]-1))%M;
	return 0;
}