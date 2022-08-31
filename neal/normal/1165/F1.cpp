#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2e5 + 5;

int N, M;
vector<int> K;
vector<int> sale[2 * MAX + 1];
vector<int> sale_dates[MAX];

bool finish(int days) {
    vector<int> original = K;
    long long money = 0;

    for (int d = 1; d <= days; d++) {
        money++;

        for (int t : sale[d]) {
            // Make sure this is the last sale date for this item
            auto it = lower_bound(sale_dates[t].begin(), sale_dates[t].end(), days + 1);
            it--;

            if (d < *it)
                continue;

            int buy = min(money, (long long) K[t]);
            money -= buy;
            K[t] -= buy;
        }
    }

    for (int t = 0; t < N; t++)
        money -= 2 * K[t];

    K = original;
    return money >= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    K.resize(N);

    for (auto &k : K)
        cin >> k;

    for (int i = 0; i < M; i++) {
        int d, t;
        cin >> d >> t;
        t--;
        sale[d].push_back(t);
        sale_dates[t].push_back(d);
    }

    for (int t = 0; t < N; t++)
        sort(sale_dates[t].begin(), sale_dates[t].end());

    int low = 0, high = 2 * MAX;

    while (low < high) {
        int mid = (low + high) / 2;

        if (finish(mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
}