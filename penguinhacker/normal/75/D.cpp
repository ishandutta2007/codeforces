#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class T> ostream& operator<< (ostream& out, vector<T> v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}

template<class T> ostream& operator<< (ostream& out, set<T> v) {
	return out << vector<T>(v.begin(), v.end());
}

template<class A, unsigned int sz> ostream& operator<< (ostream& out, ar<A, sz> a) {
	out << '[';
	for (int i = 0; i < sz; ++i) {
		if (i > 0) out << ", ";
		out << a[i];
	}
	return out << ']';
}

int n, m, t[250000];
vector<int> a[50];
ar<int, 3> b[50];
ll ans=-1000, p[250000], s[250000];
bool vis[50];

void init() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		int k;
		cin >> k;
		a[i].resize(k);
		int sum=0;
		for (int& j : a[i]) {
			cin >> j;
			sum+=j;
			b[i][0]=min(b[i][0], sum);
		}
		b[i][1]=sum, sum=0;
		for (int j=k-1; ~j; --j) {
			sum+=a[i][j];
			b[i][2]=min(b[i][2], sum);
		}
	}
	for (int i=0; i<m; ++i) {
		cin >> t[i], --t[i];
		vis[t[i]]=1;
	}
	int mx=-696969;
	for (int i=0; i<n; ++i)
		if (vis[i])
			for (int j : a[i])
				mx=max(mx, j);
	if (mx<=0) {
		cout << mx;
		exit(0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	ll sum=0;
	for (int i=0; i<m; ++i) {
		p[i]=sum+b[t[i]][0];
		sum+=b[t[i]][1];
	}
	sum=0;
	for (int i=m-1; ~i; --i) {
		s[i]=sum+b[t[i]][2];
		if (i+1<m)
			s[i]=min(s[i], s[i+1]);
		sum+=b[t[i]][1];
	}
	ll best=69696969;
	for (int i=0; i+1<m; ++i)
		best=min(best, p[i]+s[i+1]);
	ans=sum-best;
	for (int i=0; i<n; ++i) {
		if (vis[i]) {
			int cur=0;
			for (int j : a[i]) {
				cur=max(j, cur+j);
				ans=max(ans, (ll)cur);
			}
		}
	}
	cout << ans;
	return 0;
}