#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;
int n, a[mxN], b[mxN], c[mxN], d[mxN];

bool dc(vector<int> &v, int tr=0) {
	if(v.size()<3)
		return 1;
	vector<int> x1{INT_MAX}, x2{INT_MAX};
	for(int i : v) {
		x1.push_back(a[i]);
		x2.push_back(c[i]);
	}
	sort(x1.begin(), x1.end());
	sort(x2.begin(), x2.end());
	int px;
	for(int i=0, j=0, s=0; i<x1.size()-1||j<x2.size()-1; ) {
		int cx;
		if(x2[j]<=x1[i]) {
			--s;
			cx=x2[j++];
		} else {
			++s;
			cx=x1[i++];
		}
		if(!s) {
			px=cx;
			break;
		}
	}
	if(px<x2[x2.size()-2]) {
		vector<int> p1, p2;
		for(int i : v) {
			if(a[i]<px)
				p1.push_back(i);
			else
				p2.push_back(i);
		}
		return dc(p1)&&dc(p2);
	}
	if(!tr) {
		for(int i : v) {
			swap(a[i], b[i]);
			swap(c[i], d[i]);
		}
		return dc(v, 1);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<int> v(n);
	iota(v.begin(), v.end(), 0);
	cout << (dc(v)?"YES":"NO");
}