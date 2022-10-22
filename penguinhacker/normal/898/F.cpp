#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=1e9+7;
int n;
string s;
ll p[mxN+1], po[mxN+1];

void check(string a, string b, string c) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());
	string r(max(a.size(), b.size()), '0');
	int x=0;
	for (int i=0; i<r.size(); ++i) {
		x+=(i<a.size()?a[i]-'0':0)+(i<b.size()?b[i]-'0':0);
		r[i]='0'+x%10;
		x/=10;
	}
	if (x)
		r.push_back('1');
	if (r==c) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		reverse(c.begin(), c.end());
		cout << a << "+" << b << "=" << c;
		exit(0);
	}
}

ll hsh(int l, int r) {
	return (p[r+1]-p[l]*po[r-l+1]%M+M)%M;
}

void check(int a, int b, int c) {
	assert(a+b+c==n);
	if (a<=0||b<=0||c<=0)
		return;
	int sa=0, sb=a, sc=a+b;
	if (s[sa]=='0'&&a>1||s[sb]=='0'&&b>1||s[sc]=='0'&&c>1)
		return;
	if ((hsh(sa, sa+a-1)+hsh(sb, sb+b-1))%M==hsh(sc, sc+c-1))
		check(s.substr(sa, a), s.substr(sb, b), s.substr(sc, c));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s, n=s.size();
	po[0]=1;
	for (int i=0; i<n; ++i) {
		p[i+1]=(10*p[i]+s[i]-'0')%M;
		po[i+1]=10*po[i]%M;
	}
	for (int i=1; i<n; ++i) {
		check(i, n-2*i, i);
		check(i-1, n-2*i+1, i);
		check(n-2*i, i, i);
		check(n-2*i+1, i-1, i);
	}
	assert(0);
	return 0;
}