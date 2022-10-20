#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n, d;
long long sum= 0;
int a[N];
pair<int ,int > b[N * 2];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++) {
        if(a[i] == a[i - 1]) continue;
        sum += abs(a[i] - a[i - 1]);
        b[++d] = make_pair(a[i], a[i - 1]);
        b[++d] = make_pair(a[i - 1], a[i]);
    }
    sort(b + 1, b + d + 1);
    int vt1 = 1;
    long long res = sum;
    while(vt1 <= d) {
        int vt2 = vt1;
        while(vt2 <= d && b[vt2].first == b[vt1].first) vt2++;
        int m = (vt1 + vt2 - 1) >> 1;
        long long delta = 0;
        for(int i = vt1; i < vt2; i++)
            delta += abs(b[m].second - b[i].second) - abs(b[i].second - b[vt1].first);
        res = min(res, sum + delta);
        vt1 = vt2;
    }
    cout << res;
    return 0;
}