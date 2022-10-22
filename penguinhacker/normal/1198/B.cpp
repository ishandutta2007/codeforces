#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, last, a[200000];
int qry[200000][3];
bool done[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	cin >> q;
	for (int i=0; i<q; ++i) {
		cin >> qry[i][0] >> qry[i][1];
		if (qry[i][0]==1)
			cin >> qry[i][2];
	}
	int sufMax=0;
	for (int i=q-1; ~i; --i) {
		int type=qry[i][0];
		if (type==1) {
			int p=--qry[i][1], x=qry[i][2];
			if (done[p])
				continue;
			a[p]=max(x, sufMax);
			done[p]=1;
		}
		else
			sufMax=max(sufMax, qry[i][1]);
	}
	for (int i=0; i<n; ++i) {
		if (!done[i])
			a[i]=max(a[i], sufMax);
		cout << a[i] << ' ';
	}
	return 0;
}