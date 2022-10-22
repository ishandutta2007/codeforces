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
		for (int& i : a)
			cin >> i;
		sort(a.begin(), a.end());
		vector<int> b;
		for (int i : a) {
			if (b.size()>=3&&i==b.back()&&i==b.end()[-2]&&i==b.end()[-3])
				continue;
			b.push_back(i);
		}
		if (b.size()>=10) {
			cout << "NO\n";
			continue;
		}
		bool ok=1;
		for (int i=0; i<b.size(); ++i)
			for (int j=i+1; j<b.size(); ++j)
				for (int k=j+1; k<b.size(); ++k) {
					bool ok2=0;
					for (int l=0; l<b.size(); ++l)
						ok2|=b[i]+b[j]+b[k]==b[l];
					ok&=ok2;
				}
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}