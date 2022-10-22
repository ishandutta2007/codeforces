#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, c[1000];
string vitamins[1000];
int ans = 1e8;

void solve() {
    int minAB, minBC, minAC, minA, minB, minC;
    minAB = minBC = minAC = minA = minB = minC = 1e8;
    for (int i=0; i<n; ++i) {
        if (vitamins[i].size() == 3) ans = min(ans, c[i]);
        else if (vitamins[i].size() == 2) {
            bool boolA, boolB, boolC;
            boolA = boolB = boolC = false;
            for (int j=0; j<2; ++j) {
                if (vitamins[i][j] == 'A') boolA = true;
                else if (vitamins[i][j] == 'B') boolB = true;
                else boolC = true;
            }
            if (!boolC) minAB = min(minAB, c[i]);
            else if (!boolA) minBC = min(minBC, c[i]);
            else minAC = min(minAC, c[i]);
        }
        else {
            if (vitamins[i][0] == 'A') minA = min(minA, c[i]);
            else if (vitamins[i][0] == 'B') minB = min(minB, c[i]);
            else minC = min(minC, c[i]);
        }
    }
    minB = min(minB, minBC); minB = min(minB, minAB);
    minA = min(minA, minAC); minA = min(minA, minAB);
    minC = min(minC, minBC); minC = min(minC, minAC);

    ans = min(ans, minAB + minC);
    ans = min(ans, minBC + minA);
    ans = min(ans, minAC + minB);
    ans = min(ans, minA+minB+minC);

    if (ans != 1e8) cout << ans << '\n';
    else cout << -1 << '\n';
}

int main() {
	cin >> n;
    for (int i=0; i<n; ++i) cin >> c[i] >> vitamins[i];
	
    solve();
	return 0;
}