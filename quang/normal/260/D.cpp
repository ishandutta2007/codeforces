#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int N = 100010;

int n;
vector < pair<int, int> > a[2];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int c, s;
        cin >> c >> s;
        a[c].push_back(make_pair(s, i));
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    int cur0 = 0, cur1 = 0;
    for(int i = 1; i <= n - 1; i++) {
        int x = min(a[0][cur0].first, a[1][cur1].first);
        cout << a[0][cur0].second << " " << a[1][cur1].second << " " << x << endl;
        a[0][cur0].first -= x, a[1][cur1].first -= x;
        if(a[0][cur0].first < a[1][cur1].first && cur0 < a[0].size() - 1) {
            cur0++;
            continue;
        }
        if(a[0][cur0].first >= a[1][cur1].first && cur1 < a[1].size() - 1)
            cur1++;
        else cur0++;
    }
    return 0;
}