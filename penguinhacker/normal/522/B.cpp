#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, s=0, w[200000], h[200000];
pair<int, int> mxH={0, 0}; //<height, cnt>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> w[i] >> h[i];
		s+=w[i];
		if (h[i]>mxH.first)
			mxH={h[i], 1};
		else if (h[i]==mxH.first)
			mxH.second++;
	}

	for (int i=0; i<n; ++i) {
		int a=s-w[i], b=0;
		if (h[i]<mxH.first||mxH.second>1)
			b=mxH.first;
		else {
			for (int j=0; j<n; ++j)
				if (j!=i)
					b=max(b, h[j]);
		}
		cout << a*b << ' ';
	}
	return 0;
}