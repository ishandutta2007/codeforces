#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
int t[N];
int n;

void inc(int i, int d){
    for (; i < n; i = (i | (i + 1))){
        t[i] += d;
    }
}

int get(int r){
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1){
        ans += t[r];
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        cin >> n;
        vector<int> a(n), u;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            u.pb(a[i]);
        }
        sort(u.begin(), u.end());
        u.erase(unique(u.begin(), u.end()), u.end());
        for (int i = 0; i < n; i++){
            a[i] = lower_bound(u.begin(), u.end(), a[i]) - u.begin();
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += min(get(a[i] - 1), get(n - 1) - get(a[i]));
            inc(a[i], 1);
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) t[i] = 0;
    }
    return 0;
}