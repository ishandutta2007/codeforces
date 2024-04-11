#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll s[3333];
ll c[3333];
ll d[3333][3];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    ll r = 1e18;
    for (int i = 1; i <= n; i++) {
        d[i][0] = c[i];
        d[i][1] = 1e18;
        d[i][2] = 1e18;
        for (int j = 1; j <= i-1; j++) {
            if (s[j] < s[i]) {
                d[i][1] = min(d[i][1],d[j][0]+c[i]);
                d[i][2] = min(d[i][2],d[j][1]+c[i]);
            }
        }
        r = min(r,d[i][2]);
    }
    if (r == 1e18) r = -1;
    cout << r << "\n";
}