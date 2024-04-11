#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mp;
        bool x = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            mp[a]++;
        }
        for (auto to : mp){
            if (to.second >= 2){
                x = 1;
            }
        }
        if (x){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}