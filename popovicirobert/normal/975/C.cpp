#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 2e5;

ll arr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    int pos = 1;
    ll bonus = 0;
    while(q > 0) {
        q--;
        ll val;
        cin >> val;
        val += bonus;
        int res = pos - 1;
        for(int step = 1 << 17; step; step >>= 1) {
            if(res + step <= n && arr[res + step] - arr[pos - 1] <= val) {
                res += step;
            }
        }
        val -= (arr[res] - arr[pos - 1]);
        pos = res + 1;
        bonus = val;
        if(pos == n + 1) {
            pos = 1;
            bonus = 0;
        }
        cout << n - pos + 1 << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}