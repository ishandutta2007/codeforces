#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, m, a[100], b[100];
	cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];
    cin >> m;
	for (int i=0; i<m; ++i) cin >> b[i];
    sort(a, a+n); sort(b, b+m);

    int pairs = 0;
    int curB = 0;
    int curG = 0;
    while (curB < n && curG < m) {
        if (abs(a[curB] - b[curG]) <= 1) {
            pairs++;
            curB++;
            curG++;
        }
        else if (a[curB] < b[curG]) curB++;
        else curG++;
    }

    cout << pairs <<'\n';
	return 0;
}