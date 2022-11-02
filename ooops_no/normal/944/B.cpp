#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int cnt(vector<int> a, vector<int> b){
    map<int,int> mp;
    for (auto to : a) mp[to]++;
    int cnt = 0;
    for (auto to : b){
        if (mp[to]){
            cnt++;
            mp[to]--;
        }
    }
    return cnt;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> u;
    for (int i = 0; i < n; i++){
        cin >> x[i];
        u.pb(x[i]);
    }
    int cnt_mn = 0, cnt_mx = 0, cnt_mid = 0;
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    if (u.size() <= 2 && u.back() - u[0] == 1){
        cout << n << endl;
        for (auto to : x){
            cout << to << ' ';
        }
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (x[i] == u.back()){
            cnt_mx++;
        }
        else if (x[i] == u[0]){
            cnt_mn++;
        }
        else{
            cnt_mid++;
        }
    }
    vector<int> a;
    for (int i = 0; i < cnt_mn; i++){
        a.pb(u[0]);
    }
    for (int i = 0; i < cnt_mx; i++){
        a.pb(u.back());
    }
    for (int i = 1; i < cnt_mid; i += 2){
        a.pb(u[0]);
        a.pb(u.back());
    }
    if (cnt_mid % 2 == 1){
        a.pb(u[1]);
    }
    int anss = cnt(a, x);
    vector<int> b;
    for (int i = 0; i < min(cnt_mn, cnt_mx); i++){
        b.pb(u.back() - 1);
        b.pb(u.back() - 1);
    }
    for (int i = 0; i < cnt_mid; i++){
        b.pb(u.back() - 1);
    }
    for (int i = 0; i < cnt_mn - min(cnt_mn, cnt_mx); i++){
        b.pb(u[0]);
    }
    for (int i = 0; i < cnt_mx - min(cnt_mn, cnt_mx); i++){
        b.pb(u.back());
    }
    if (cnt(b, x) < anss){
        a = b;
    }
    cout << cnt(a, x) << endl;
    for (auto to : a){
        cout << to << ' ';
    }
    return 0;
}