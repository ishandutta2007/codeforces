#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int k, best=0;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> k;
	for (int i=(s.size()+k)/2; i>=1; --i) {
		bool pos=0;
		for (int j=0; j<=k+s.size()-2*i; ++j) {
			bool b=1;
			for (int p=j; p<j+i; ++p) {
				if (p+i<s.size()&&s[p]!=s[p+i]) {
					b=0;
					break;
				}
				if (p+i>=s.size())
					break;
			}
			if (b) {
				pos=1;
				break;
			}
		}
		if (pos) {
			best=i;
			break;
		}
	}
	cout << 2*best;
	return 0;
}