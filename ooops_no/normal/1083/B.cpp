#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define F first
#define S second
#define int long long
typedef long long ll;

mt19937 rnd(51);

const int INF = 1e9;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    int i = 0;
    while(i < n && s[i] == t[i]){
        ans++;
        i++;
    }
    s = s.substr(i, n - i);
    t = t.substr(i, n - i);
    if (i == n){
        cout << ans << endl;
    }
    else{
        n = s.size();
        vector<int> col(n + 1), need(n + 3), coll(n);
        int free = 0;
        for (int i = 0; i < n; i++){
            if (i == 0){
                col[n - i] = 2;
            }
            else{
                free = min(INF, free * 2);
                if (s[i] == 'a'){
                    coll[i]++;
                    need[i + 1]++;
                }
                if (t[i] == 'b'){
                    coll[i]++;
                    need[i + 1]++;
                }
                free += need[i];
                col[n - i] += free + coll[i];
            }
        }
        for (int i = n; i >= 0; i--){
            if (col[i] >= k){
                ans += k * i;
                break;
            }
            ans += col[i] * i;
            k -= col[i];
        }
        cout << ans << endl;
    }
    return 0;
}