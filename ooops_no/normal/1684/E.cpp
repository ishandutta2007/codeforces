#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

int solve(int n, int k, vector<int> a) {
    int sum = 0, res = 0, ans = n, total_res = 0;
    vector<int> need(n + 1);
    map<int,int> cnt;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        need[i] = need[i - 1];
        if (cnt.find(i - 1) == cnt.end()) {
            need[i]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (cnt.find(i) != cnt.end()) {
            res += cnt[i] - 1;
        }
    }
    ans = min(ans, (int)cnt.size());
    for (auto to : cnt) {
        if (to.first > n) {
            res += to.second;
            total_res++;
            if (sum + to.second <= k) {
                st.insert(to.second);
                sum += to.second;
            } else {
                if (st.size() > 0 && to.second < *st.rbegin()) {
                    sum -= *st.rbegin();
                    st.erase(st.find(*st.rbegin()));
                    sum += to.second;
                    st.insert(to.second);
                }
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (cnt.find(i) != cnt.end()) {
            res += 1;
            total_res++;
            if (sum + cnt[i] <= k) {
                st.insert(cnt[i]);
                sum += cnt[i];
            } else {
                if (st.size() > 0 && cnt[i] < *st.rbegin()) {
                    sum -= *st.rbegin();
                    st.erase(st.find(*st.rbegin()));
                    sum += cnt[i];
                    st.insert(cnt[i]);
                }
            }
        }
        if (need[i] > min(res, k)) continue;
        ans = min(ans, total_res - (int)st.size());
    }
    return ans;
}

int solvee(int n, int k, vector<int> a) {
    int ans = n;
    map<int,int> cnt;
    for (auto to : a) {
        cnt[to]++;
    }
    for (int i = 0; i <= n; i++) {
        int need = 0, can = 0, res = 0;
        multiset<int> st;
        for (int j = 0; j < i; j++) {
            if (cnt.find(j) == cnt.end()) need++;
        }
        for (auto to : cnt) {
            if (to.first >= i) {
                can += to.second;
                res++;
                st.insert(to.second);
            }
        }
        if (need > min(can, k)) continue;
        int Lef = k;
        for (auto to : st) {
            if (to <= Lef) {
                Lef -= to;
                res--;
            }
        }
        ans = min(ans, res);
    }
    return ans;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(n, k, a) << endl;
    }
    return 0;
}