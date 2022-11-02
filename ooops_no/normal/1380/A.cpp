#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
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
        vector<int> p(n);
        bool x = 0;
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        for (int i = 0; i < n; i++){
            int f = -1, s = -1;
            for (int j = i + 1; j < n; j++){
                if (p[j] < p[i]) s = j;
            }
            for (int j = i - 1; j >= 0; j--){
                if (p[j] < p[i]) f = j;
            }
            if (f == -1 || s == -1) continue;
            x = 1;
            cout << "YES\n";
            cout << f + 1 << ' ' << i + 1 << ' ' << s + 1 << endl;
            break;
        }
        if (!x) cout << "NO\n";
    }
    return 0;
}