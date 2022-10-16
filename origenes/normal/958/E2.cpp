// E2

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 500000 + 10;

int t[N], itv[N], n, K, sz;

int t2[N];
void deal() {
    for(int i = 1; i < n; i++) itv[i - 1] = t[i] - t[i - 1];
    nth_element(itv, itv + 2 * K, itv + n - 1);
    int val = itv[2 * K];

    int cnt = 0;
    sz = 0;
    bool first = true;
    for(int i = 0; i < n - 1; i++)
        if(t[i + 1] - t[i] < val || (t[i + 1] - t[i] == val && cnt < 2 * K)) {
            if(first) { t2[sz++] = t[i]; first = false; }
            t2[sz++] = t[i + 1];
            if(t[i + 1] - t[i] == val) cnt++;
        } else {
            first = true;
        }

    for(int i = 0; i < sz; i++) t[i] = t2[i];
}

int d[N][2];

int solve() {
    memset(d, 0x3f, sizeof(d));
    d[0][1] = 0;
    for(int i = 1; i < sz; i++)
        for(int j = K; j >= 1; j--) {
            d[j][1] = min(d[j][0], d[j][1]);
            d[j][0] = d[j - 1][1] + t[i] - t[i - 1];
        }
    return min(d[K][0], d[K][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> n;
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(t, t + n);
    sz = n;

    if(n >= 5 * K) deal();
    cout << solve() << '\n';
    return 0;
}