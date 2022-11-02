#include <iostream>
#include <iomanip>

using namespace std;
const int N = 10;
const int L = 1e4 + 10;

int l[N], r[N];

int main() {
    int n{};
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    double ans{};
    for (int cost = 1; cost <= L; cost++)
        for (int suggest = 1; suggest <= n; suggest++) {
            if (cost < l[suggest] || cost > r[suggest])
                continue;
            for (int win = 1; win <= n; win++) {
                if (win == suggest || cost > r[win])
                    continue;
                int poss{min(r[win] - cost, r[win] - l[win] + 1)};
                bool extra_try = (win > suggest && l[win] <= cost && cost <= r[win] ? true : false);
                long long all{1}, cnt_for_extra_try{1}, cnt{1};
                for (int i = 1; i <= n; i++) {
                    if (i == win || i == suggest)
                        continue;
                    all *= r[i] - l[i] + 1;
                    if (i < suggest)
                        cnt *= (cost < l[i] + 1 ? 0 : min(cost - l[i], r[i] - l[i] + 1));
                    else
                        cnt *= (cost < l[i] ? 0 : min(cost - l[i] + 1, r[i] - l[i] + 1));
                    if (i < win || i < suggest)
                        cnt_for_extra_try *= (cost < l[i] + 1 ? 0 : min(cost - l[i], r[i] - l[i] + 1));
                    else
                        cnt_for_extra_try *= (cost < l[i] ? 0 : min(cost - l[i] + 1, r[i] - l[i] + 1));
                }
                ans += (cnt + 0.0) / all * poss / (r[win] - l[win] + 1) / (r[suggest] - l[suggest] + 1) * cost;
                if (extra_try)
                    ans += (cnt_for_extra_try + 0.0)/ all / (r[win] - l[win] + 1) / (r[suggest] - l[suggest] + 1) * cost;
            }
        }
    cout << setprecision(9) << fixed << ans << "\n";
    return 0;
}