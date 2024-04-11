#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; ++i)
			cin >> a[i];
		if (n==1) {
			cout << (a[0]==0?"YES":"NO") << "\n";
			continue;
		}
		if (a.back()>0) {
			cout << "NO\n";
			continue;
		}
		vector<ll> b(n-1);
		b[n-2]=-a[n-1];
		bool ok=1;
		for (int i=n-2; i; --i) {
			// a[i]=b[i]-b[i-1];
			// b[i-1]=b[i]-a[i];
			//cout << i << " " << b[i-1] << endl;
			b[i-1]=b[i]-a[i];
			if (b[i-1]<0) {
				ok=0;
				break;
			}
		}
		ok&=a[0]==b[0];
		if (ok) {
			auto it=find(b.begin(), b.end(), 0);
			if (it!=b.end()) {
				int pos=it-b.begin();
				for (int i=pos+1; i<n-1; ++i)
					if (b[i]) {
						//cout << i << " " << b[i] << endl;
						assert(b[i]>0);
						ok=0;
						break;
					}
			}
		}
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}