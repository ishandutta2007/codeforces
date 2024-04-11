#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e6 + 10;
vector<int> a(N);
vector<int> cnt(61);

int solve(int l, int r){
    if (l == r){
        return 1;
    }
    int mid = (l + r) / 2;
    int ans = solve(l, mid) + solve(mid + 1, r);
    vector<int> mnl, mxl, mnr, mxr;
    deque<int> b;
    int mn = a[mid], mx = a[mid];
    for (int i = mid; i >= l; i--){
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        mnl.pb(mn);
        mxl.pb(mx);
    }
    mn = a[mid + 1], mx = a[mid + 1];
    for (int i = mid + 1; i <= r; i++){
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        mnr.pb(mn);
        mxr.pb(mx);
    }
    int n = mnl.size(), m = mnr.size(), j = 0, can = 0;
    for (int i = 0; i < m; i++){
        while(j < n && mxl[j] < mxr[i]){
            b.pb(mnl[j]);
            cnt[__builtin_popcountll(mnl[j])]++;
            j++;
        }
        while(b.size() > 0 && b.front() >= mnr[i]){
            can++;
            cnt[__builtin_popcountll(b.front())]--;
            b.pop_front();
        }
        ans += cnt[__builtin_popcountll(mxr[i])];
        if (__builtin_popcountll(mxr[i]) == __builtin_popcountll(mnr[i])){
            ans += can;
        }
    }
    for (auto to : b) cnt[__builtin_popcountll(to)]--;
    b.clear();
    j = 0, can = 0;
    for (int i = 0; i < n; i++){
        while(j < m && mxr[j] <= mxl[i]){
            b.pb(mnr[j]);
            cnt[__builtin_popcountll(mnr[j])]++;
            j++;
        }
        while(b.size() > 0 && b.front() >= mnl[i]){
            can++;
            cnt[__builtin_popcountll(b.front())]--;
            b.pop_front();
        }
        ans += cnt[__builtin_popcountll(mxl[i])];
        if (__builtin_popcountll(mxl[i]) == __builtin_popcountll(mnl[i])){
            ans += can;
        }
    }
    for (auto to : b) cnt[__builtin_popcountll(to)]--;
    return ans;
}

int solvee(int l, int r, int n){
    int ans = 0;
    for (int i = 0; i < n; i++){
        int mn = a[i], mx = a[i];
        for (int j = i; j < n; j++){
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            ans += (__builtin_popcountll(mn) == __builtin_popcountll(mx));
        }
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(0, n - 1) << endl;
    return 0;
}