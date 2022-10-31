#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const __int128 INF = 1e18;

int mul(int a, int b){
    __int128 c = a;
    c *= b;
    c = min(c, INF);
    return c;
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
        int n, k, x, cnt = 0;
        cin >> n >> k >> x;
        string s;
        cin >> s;
        vector<int> a, mn;
        for (int i = 0; i < n; i++){
            if (s[i] == '*') cnt++;
            else{
                if (cnt > 0) a.pb(cnt * k);
                cnt = 0;
                a.pb(-1);
            }
        }
        if (cnt > 0) a.pb(cnt * k);
        mn.resize(a.size() + 1);
        mn.back() = 1;
        for (int i = (int)(a.size()) - 1; i >= 0; i--){
            if (a[i] == -1){
                mn[i] = mn[i + 1];
            }
            else{
                mn[i] = mul(a[i] + 1, mn[i + 1]);
            }
        }
        for (int i = 0; i < a.size(); i++){
            if (a[i] == -1){
                cout << 'a';
            }
            else{
                for (int j = 0; j < a[i]; j++){
                    if (mn[i + 1] >= x) break;
                    x -= mn[i + 1];
                    cout << 'b';
                }
            }
        }
        cout << endl;
    }
    return 0;
}