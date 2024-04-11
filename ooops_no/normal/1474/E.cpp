#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define ld long double

using namespace std;

mt19937 rnd(51);

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
        if (n == 2){
            cout << "1\n2 1\n1\n2 1\n";
        }
        else{
            vector<int> pr(n), sf(n);
            int anss = 0, now = 0;
            for (int i = 1; i < n; i++){
                pr[i] = (n - i - 1) * (n - i - 1) + pr[i - 1];
            }
            for (int i = n - 2; i >= 0; i--){
                sf[i] = i * i + sf[i + 1];
            }
            for (int i = 1; i < n - 1; i++){
                if (pr[i] + sf[i + 1] > anss){
                    anss = pr[i] + sf[i + 1];
                    now = i;
                }
            }
            anss += (n - 1) * (n - 1);
            int j = 1;
            vector<int> ans(n);
            for (int i = 1; i <= now; i++){
                ans[i] = j++;
            }
            ans[n - 1] = j++;
            ans[0] = j++;
            for (int i = now + 1; i < n - 1; i++){
                ans[i] = j++;
            }
            cout << anss << endl;
            for (auto to : ans) cout << to << ' ';
            cout << endl;
            cout << n - 1 << endl;
            for (int i = now; i >= 1; i--){
                cout << i + 1 << ' ' << n << endl;
            }
            for (int i = now + 1; i < n - 1; i++){
                cout << i + 1 << ' ' << 1 << endl;
            }
            cout << 1 << ' ' << n << endl;
        }
    }
    return 0;
}