#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    map <vector < pair <int, int> >, int> mp;
    ll ans = 0, num = 0;

    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;

        vector < pair <int, int> > cur;

        int d = 2;
        while(d * d <= x) {
            int e = 0;
            while(x % d == 0) {
                x /= d;
                e++;
            }
            if(e % k > 0) {
                cur.push_back({d, k - e % k});
            }
            d++;
        }
        if(x > 1) {
            cur.push_back({x, k - 1});
        }

        ans += mp[cur];
        for(auto &it : cur) {
            it.second = k - it.second;
        }

        mp[cur]++;
    }

    cout << ans;

    return 0;
}