#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5+10, M=998244353;
ll f[mxN], iv[mxN], iF[mxN];

ll C(int a, int b) {
	return f[a]*iF[b]%M*iF[a-b]%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[1]=iv[1]=iF[1]=iF[0]=f[0]=1;
	for (int i=2; i<mxN; ++i) {
		f[i]=i*f[i-1]%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iv[i]*iF[i-1]%M;
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		int one=0;
		int zero=count(s.begin(), s.end(), '0');
		for (int i=0; i<n; ++i) {
			if (s[i]=='0')
				continue;
			int j=i;
			while(j+1<n&&s[j]==s[j+1])
				++j;
			one+=(j-i+1)/2;
			i=j;
		}
		cout << C(one+zero, one) << "\n";
	}
	return 0;
}