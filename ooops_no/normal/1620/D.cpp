#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

int clever(vector<int> a){
    vector<int> was(3);
    map<int,int> cnt;
    for (auto to : a){
        cnt[to]++;
        was[to % 3] = 1;
    }
    if (a.back() % 3 == 0){
        int ans = a.back() / 3;
        if (was[1] || was[2]) ans++;
        return ans;
    }
    else if (a.back() % 3 == 1){
        int ans = a.back() / 3;
        if (!was[2] || (cnt[1] == 0 && cnt[a.back() - 1] == 0)) ans++;
        else ans += 2;
        return ans;
    }
    else{
        int ans = a.back() / 3;
        if (!was[1]) ans++;
        else ans += 2;
        return ans;
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << clever(a) << endl;
    }
    return 0;
}