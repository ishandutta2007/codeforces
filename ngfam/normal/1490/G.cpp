#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        cin >> a[n-1]; 
        for(int i = 0; i < n-1; ++i) cin >> a[i];

        long long sum = 0;       
        vector<pair<long long, int>> bests(1, make_pair(0, 0));

        for(int i = 0; i < n; ++i) {
            sum += a[i];
            if (sum > bests.back().first) bests.emplace_back(sum, i+1);
        }

        while(m--) {
            long long x; cin >> x;
            x -= a[n-1];
            if (x <= bests.back().first) {
                auto fpos = lower_bound(bests.begin(), bests.end(), make_pair(x, -1));
                cout << fpos->second << " ";
            }
            else {
                if (sum <= 0) {
                    cout << -1 << " ";
                }
                else {
                    int times = (x - bests.back().first + sum - 1) / sum;
                    x -= 1ll * times * sum;
                    auto fpos = lower_bound(bests.begin(), bests.end(), make_pair(x, -1));
                    cout << fpos->second + 1LL * n * times << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}