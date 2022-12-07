#include <bits/stdc++.h>
#define long long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        vector<int> a(n);

        long sum = 0;
        for(int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
        
        if ((2 * sum) % n != 0) {
            cout << 0 << "\n";
            continue;
        }

        long delta = (2 * sum) / n;
        
        long ans = 0;
        map<long, int> cnt;
        for(int i = 0; i < n; ++i) {
            ans += cnt[delta - a[i]];
            cnt[a[i]]++;
        }

        cout << ans << "\n";
    }

    return 0;
}