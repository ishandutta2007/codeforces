#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int ans(vector<int> a, vector<int> b){
    if (a.size() == 0 || b.size() == 0){
        return 0;
    }
    int n = a.size(), m = b.size();
    map<int,int> mp;
    for (int i = 0; i < a.size(); i++) a[i] = abs(a[i]);
    for (int i = 0; i < b.size(); i++) b[i] = abs(b[i]);
    for (auto to : a){
        mp[to] = 1;
    }
    vector<int> pr(m), need(m);
    for (int i = m - 1; i >= 0; i--){
        pr[i] = mp[b[i]];
        if (i + 1 < m) pr[i] += pr[i + 1];
    }
    int j = 0, cnt = 0, ans = 0;
    for (int i = 0; i < m; i++){
        while(j < a.size() && a[j] <= b[i]){
            cnt++;
            j++;
        }
        need[i] = cnt;
    }
    ans = max(ans, pr[0]);
    for (int i = 0; i < m; i++){
        if (need[i] == 0){
            continue;
        }
        int l = i, r = m;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (b[mid] - b[i] + 1 <= need[mid]){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        if (l == m - 1){
            ans = max(ans, (l - i + 1));
        }
        else{
            ans = max(ans, (l - i + 1) + pr[l + 1]);
        }
    }
    return ans;
}

int solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a, aa, b, bb;
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        if (v < 0){
            a.pb(v);
        }
        else{
            aa.pb(v);
        }
    }
    for (int i = 0; i < m; i++){
        int v;
        cin >> v;
        if (v < 0){
            b.pb(v);
        }
        else{
            bb.pb(v);
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    return (ans(a, b) + ans(aa, bb));
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}