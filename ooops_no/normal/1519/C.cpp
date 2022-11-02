#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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
        int n;
        cin >> n;
        vector<vector<int>> s(n + 1);
        vector<int> u(n);
        for (int i = 0; i < n; i++){
            cin >> u[i];
        }
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            s[u[i]].pb(a);
        }
        for (int i = 1; i <= n; i++){
            sort(s[i].rbegin(), s[i].rend());
        }
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++){
            if (s[i].size() > 0){
                vector<int> pr(s[i].size());
                for (int j = 0; j < s[i].size(); j++){
                    pr[j] = s[i][j];
                    if (j > 0) pr[j] += pr[j - 1];
                    sum[j + 1] += pr[j];
                }
                for (int j = 1; j < s[i].size(); j++){
                    for (int k = 1; k <= sqrt(j); k++){
                        if (j % k == 0){
                            if (j + k <= s[i].size()){
                                sum[k] += pr[j + k - 1] - pr[j - 1];
                            }
                            if (j + j / k <= s[i].size() && k != j / k){
                                sum[j / k] += pr[j + j / k - 1] - pr[j - 1];
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++){
            cout << sum[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}