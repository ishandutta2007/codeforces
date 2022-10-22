#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int s, n, a[1000], b[1000];
	cin >> n >> s;
	for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) cin >> b[i];

    bool valid = 0;
    if (a[0]==1) {
        if (a[s-1]==1) valid = 1;
        else if (b[s-1]==1) {
            for (int i=s; i<n; ++i) {
                if (a[i]&&b[i]) valid = 1;
            }
        }
    }

    if (valid) cout << "YES" << '\n';
    else cout << "NO" << '\n';
	return 0;
}