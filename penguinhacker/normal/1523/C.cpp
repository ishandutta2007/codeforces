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
		vector<int> v;
		while(n--) {
			int x;
			cin >> x;
			if (x==1)
				v.push_back(x);
			else {
				while(v.size()&&v.back()!=x-1)
					v.pop_back();
				assert(v.size());
				++v.back();
			}
			for (int i=0; i<v.size(); ++i) {
				cout << v[i];
				if (i+1<v.size())
					cout << ".";
			}
			cout << "\n";
		}
	}
	return 0;
}