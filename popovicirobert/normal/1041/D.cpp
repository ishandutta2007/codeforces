#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

pair <int, int> arr[MAXN + 1];
int sp[MAXN + 1];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, h;
    ios::sync_with_stdio(false);
    cin >> n >> h;
    for(i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1, arr + n + 1);
    arr[++n] = {2e9 + 1, 2e9 + 1};
    for(i = 1; i <= n; i++) {
        sp[i] = sp[i - 1] + arr[i].second - arr[i].first;
    }
    ll ans = 0;
    for(i = 1; i < n; i++) {
        int res = i;
        for(int step = 1 << 17; step; step >>= 1) {
            if(res + step <= n && h > (arr[res + step].second - arr[i].first - (sp[res + step] - sp[i - 1]))) {
                res += step;
            }
        }
        ans = max(ans, h + (sp[res] - sp[i - 1]) + 0LL);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}