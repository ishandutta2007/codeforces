#define foru(i, k, n) for(int i = k; i < n; i++)
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int a[(size_t)1e5 + 1],n;

int foo(int i, int j) {
	if (i<0 || j>n || i >= j)return 0;
	int mx = -31, mxindex = -1;
	vector<int> mxs;
	foru(p, i, j) {
		if (mx <= a[p]) {
			if (mx == a[p])mxs.push_back(p);
			else {
				mx = a[p];
				mxs.clear();
				mxs.push_back(p);
			}
		}
	}
	mxindex = mxs[mxs.size() / 2];
	int res = max(foo(i, mxindex), foo(mxindex + 1, j));
	res = max(res, 0);
	int mxf = 0, mxb = 0,f=0,b=0;
	foru(p, mxindex + 1, j) {
		f += a[p];
		mxf = max(mxf, f);
	}
	for (int p = mxindex - 1; p >= i; p--) {
		b += a[p];
		mxb = max(mxb, b);
	}
	return max(res, mxf + mxb);
}

int main() {
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	cout << foo(0, n) << endl;
	return 0;
}