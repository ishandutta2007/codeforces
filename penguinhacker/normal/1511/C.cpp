#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, a[300000];
int oc[50];

void test_case() {
	cin >> n >> q;
	memset(oc, -1, sizeof(oc));
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		if (oc[a[i]]==-1)
			oc[a[i]]=i+1;
	}
	while(q--) {
		int t;
		cin >> t, --t;
		for (int i=0; i<50; ++i)
			if (oc[i]!=-1&&oc[t]>oc[i])
				++oc[i];
		cout << oc[t] << " ";
		oc[t]=1;
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin >> t;
	while(t--)
		test_case();
	return 0;
}