#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, w;
long long sum[N];

void add(vector<int> &val, int l) {
    vector<tuple<int, int, int>> ls;
    for (int i = 1; i <= l; i++) {
        tuple<int, int, int> now(val[i], i, w - l + i);
        if (ls.empty()) {
            ls.push_back(now);
        } else {
            while (1) {
                if (get<2>(ls.back()) < get<1>(now)) {
                    ls.push_back(now);
                    break;
                }
                if (get<0>(ls.back()) > val[i]) {
                    get<1>(now) = get<2>(ls.back()) + 1;
                    ls.push_back(now);
                    break;
                }
                if (get<1>(ls.back()) >= get<1>(now)) {
                    ls.pop_back();
                    continue;
                }
                get<2>(ls.back()) = get<1>(now) - 1;
                ls.push_back(now);
                break;
            }
        }
    }
    for (auto u : ls) {
        int val, low, high;
        tie(val, low, high) = u;
        if (val >= 0) {
            sum[low] += val;
            sum[high + 1] -= val;
        } else {
            low = max(low, w - l + 1);
            high = min(high, l);
            if (low <= high) {
                sum[low] += val;
                sum[high + 1] -= val;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector<int> val(k + 1);
        for (int j = 1; j <= k; j++) {
            cin >> val[j];
        }

        add(val, k);
    }
    for (int i = 1; i <= w; i++) {
        sum[i] += sum[i - 1];
        cout << sum[i] << ' ';
    }
    cout << endl;
    return 0;
}