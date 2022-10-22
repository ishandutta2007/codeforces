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
		int must=-1;
		bool ok=1;
		for (int& i : a) {
			cin >> i;
			if (i%10==5)
				i+=5;
			if (i%10==0) {
				if (must==-1)
					must=i;
				else if (must!=i)
					ok=0;
			} else {
				while(i%10!=2)
					i+=i%10;
			}
		}
		if (!ok) {
			cout << "No\n";
			continue;
		}
		must=a[0]%20;
		for (int i : a)
			if (i%20!=must)
				ok=0;
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}