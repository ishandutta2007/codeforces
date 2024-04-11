#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int sum = 0, summ = 0, cnt = 0, cntt = 0;
        bool good = 0;
        while (a.size() > 0) {
            sum += a.back();
            cnt++;
            a.pop_back();
            while (a.size() > 0 && summ + a.front() < sum) {
                summ += a.front();
                cntt++;
                a.pop_front();
            }
            if (cntt > cnt) {
                good = 1;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
    }
    return 0;
}