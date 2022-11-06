#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using pp=pair<int,int>;

const int maxn = int(5e2) + 10;
int n;
int a[maxn];
int b[maxn];
int h[maxn];

void No() { cout << "NO\n"; }

void Work() {
    if (a[1] != b[1]) { No(); return; }
    vector<pp> ans;
    for (int i=1; i<n; ++i) {
        if (a[i+1] == b[i+1]) continue;
        int r = -1;
        for (int j=i; j<n; ++j) {
            if (a[j] == b[i+1] && a[j+1] == b[i]) {
                r = j;
                break;
            }
        }

        if (r != -1) {
            ans.push_back({i, r+1});
            reverse(a+i, a+r+2);
            continue;
        }

        for (int j=i; j<n; ++j) {
            if (a[j] == b[i] && a[j+1] == b[i+1]) {
                r = j;
                break;
            }
        }
        if (r == -1) { No(); return; }

        for (int j=i; j<=r; ++j) h[a[j]] = j;
        int rr = -1, brr;
        for (int j=r+1; j<=n; ++j) {
            if (h[a[j]]) {
                rr = j;
                brr = h[a[j]];
                break;
            }
        }
        for (int j=i; j<=r; ++j) h[a[j]] = 0;

        if (rr == -1) { No(); return; }
        ans.push_back({brr, rr});
        reverse(a+brr, a+rr+1);
        --i; continue;
    }

    cout << "YES\n" << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

int tc; cin >> tc;
for (;tc--;) {
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i) cin >> b[i];

    Work();
}

    return 0;
}