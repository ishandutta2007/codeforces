#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

const int N = 1e5 + 10, K = 300, M = 3e7 + 2e5;
int ans = 0;
vector<int> nw(N);
int mp[M];

void solve(int n, vector<int> a) {
    for (int j = 0; j < K; j++) {
        for (int i = 0; i < n; i++) {
            mp[a[i] + i * j]++;
            ans = max(ans, mp[a[i] + i * j]);
        }
        for (int i = 0; i < n; i++) {
            mp[a[i] + i * j]--;
        }
    }
    int mx = (3 * N + K - 1) / K + 3;
    vector<int> cnt(N);
    for (int i = n - 1; i >= 0; i--) {
        int ind = 0;
        for (int j = i + 1; j < min(n, i + mx); j++) {
            int val = a[i] - a[j];
            if (val >= 0 && val % (j - i) == 0) {
                int x = val / (j - i);
                if (x < K) continue;
                cnt[x]++;
                ans = max(ans, cnt[x] + 1);
                nw[ind++] = x;
            }
        }
        for (int j = 0; j < ind; j++) {
            cnt[nw[j]] = 0;
        }
    }
}

vector<int> rev(vector<int> a) {
    reverse(a.begin(), a.end());
    return a;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = 1;
    solve(n, a), solve(n, rev(a));
    cout << n - ans << endl;
    return 0;
}