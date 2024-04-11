#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool pos = false;
int n, a[15];

void recurse(int x, int ind) {
    if (ind == n) {
        if ((x + 360*15)%360 == 0) pos = true;
    }
    else {
        recurse(x+a[ind], ind+1);
        recurse(x-a[ind], ind+1);
    }
}

int main() {
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

    recurse(0, 0);

    if (pos) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
	return 0;
}