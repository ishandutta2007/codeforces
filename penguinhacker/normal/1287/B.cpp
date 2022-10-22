#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, ans;
string s[1500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	sort(s, s+n);
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			string c(k, '0');
			for (int k2=0; k2<k; ++k2) {
				char a=s[i][k2], b=s[j][k2];
				if (a==b)
					c[k2]=a;
				else if (a!='S'&&b!='S')
					c[k2]='S';
				else if (a!='E'&&b!='E')
					c[k2]='E';
				else
					c[k2]='T';
			}
			//cout << c << "\n";
			int k2=lower_bound(s, s+n, c)-s;
			if (j<k2&&k2<n&&s[k2]==c)
				++ans;
		}
	}
	cout << ans;
	return 0;
}