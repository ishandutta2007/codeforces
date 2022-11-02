#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

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
        vector<pair<int,int>> a(n);
        vector<int> ans(n + 1);
        for (int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.rbegin(), a.rend());
        int nowl = -1, nowr = 1, cnt = 0;
        for (auto to : a){
            if (abs(nowl) < abs(nowr)){
                ans[to.second] = nowl;
                cnt += to.first * abs(nowl);
                nowl--;
            }
            else{
                ans[to.second] = nowr;
                cnt += to.first * abs(nowr);
                nowr++;
            }
        }
        cout << cnt * 2 << endl;
        for (auto to : ans){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}