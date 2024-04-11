#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	
    int group[300][300];
    for (int i=1; i<=n*n; ++i) {
        if ((i-1)%(2*n) < n) {
            group[(i-1)%(2*n)][(i-1)/n] = i;
        }
        else {
            group[2*n-1-(i-1)%(2*n)][(i-1)/n] = i;
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << group[i][j] << ' ';
        }
        cout << '\n';
    }
	return 0;
}