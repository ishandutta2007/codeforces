#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), pl(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    int l = -1, r = 1e18;
    while(r - l > 1){
        int mid = (r + l) / 2;
        fill(pl.begin(), pl.end(), 0);
        set<pair<int,int>> st;
        vector<vector<int>> need(k + 1);
        int have = 0;
        for (int i = 0; i < n; i++){
            need[min(k, a[i] / b[i])].pb(i);
        }
        bool x = 0;
        for (int i = 0; i < k - 1; i++){
            have++;
            int j = 0;
            while(j < need[i].size()){
                if (have == 0){
                    x = 1;
                    break;
                }
                have--;
                int ind = need[i][j];
                pl[ind] += mid;
                if ((a[ind] + pl[ind]) / b[ind] > i){
                    need[min(k, (a[ind] + pl[ind]) / b[ind])].pb(ind);
                    j++;
                }
            }
        }
        if (x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if (r == 1e18) cout << -1 << endl;
    else cout << r << endl;
    return 0;
}