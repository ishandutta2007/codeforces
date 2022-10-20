#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
pair<int, int> a[N];

bool check(int res, int f = 0) {
    pair<int, int> diff(-1e9, 1e9);
    pair<int, int> sum(-1e9, 1e9);
    pair<int, int> bb(-1e9, 1e9);
    pair<int, int> nn(-1e9, 1e9);
    for (int i = 1; i <= n; i++) {
        diff.first = max(diff.first, (a[i].first - a[i].second) - res);
        diff.second = min(diff.second, (a[i].first - a[i].second) + res);
        sum.first = max(sum.first, (a[i].first + a[i].second) - res * 2);
        sum.second = min(sum.second, (a[i].first + a[i].second) + res * 2);

        bb.first = max(bb.first, a[i].first - res);
        bb.second = min(bb.second, a[i].first + res);
        nn.first = max(nn.first, a[i].second - res);
        nn.second = min(nn.second, a[i].second + res);
    }
    
    if (diff.first > diff.second || sum.first > sum.second) return 0;
    if (bb.first > bb.second || nn.first > nn.second) return 0;

    for (int numB = max(0, bb.first); numB <= bb.second; numB++) {
        pair<int, int> numN = nn;
        
        numN.first = max(numN.first, sum.first - numB);
        numN.second = min(numN.second, sum.second - numB);

        numN.first = max(numN.first, numB - diff.second);
        numN.second = min(numN.second, numB - diff.first);
        if (numN.first <= numN.second && numN.second >= 0) {
            if (numB > 0 || numN.second > 0) {

                if (f) {
                    for (int i = 1; i <= numB; i++) {
                        cout << 'B';
                    }
                    for (int i = 1; i <= numN.second; i++) {
                        cout << 'N';
                    }
                    cout << endl;
                }

                return 1;
            }

        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string u;
        cin >> u;
        for (char val : u) {
            if (val == 'B') a[i].first++;
            else a[i].second++;
        }
    }

    int low = -1, high = 2e6;
    while (high - low > 1) {
        int mid = low + high >> 1;
        if (check(mid)) {
            high = mid;
        } else low = mid;
    }

    cout << high << endl;
    check(high, 1);
    return 0;
}