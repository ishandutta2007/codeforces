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
        string s;
        cin >> n >> s;
        int ans = 1;
        vector<int> pr(n), sf(n);
        int now = 0;
        for (int i = 1; i < n; i++){
            if (s[i] == s[i - 1]) now = i;
            pr[i] = now;
        }
        sf[n - 1] = now = n - 1;
        for (int i = n - 2; i >= 0; i--){
            sf[i] = now;
            if (s[i] == s[i + 1]) now = i;
        }
        for (int i = 0; i < n; i++){
            if ((i % 2 == 0 && s[i] == 'L') || (i % 2 == 1 && s[i] == 'R')) break;
            ans++;
        }
        cout << ans << " ";
        for (int i = 0; i < n; i++){
            int j = i, ans = 1, anss = 1;
            if (s[j] == 'L'){
                ans = i - pr[i] + 2;
            }
            j = i + 1;
            if (j < n && s[j] == 'R'){
                anss = sf[i] - i + 1;
            }
            cout << ans + anss - 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}