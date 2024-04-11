#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 5010;

int n;
pair<int, int> a[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        int gtmin = min(a[i].first, a[i].second);
        int gtmax = max(a[i].first, a[i].second);
        if(cur <= gtmin) cur = gtmin;
        else cur = gtmax;
    }
    cout << cur;
    return 0;
}