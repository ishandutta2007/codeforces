#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

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
        int n, ans = 0;
        cin >> n;
        vector<int> v(n);
        set<int> st;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (v[i] != 1){
                st.insert(i);
            }
        }
        for (int i = 0; i < n; i++){
            if (v[i] == 1) continue;
            if (i + v[i] >= n){
                int val = min(v[i] - 1, (i + v[i] - n + 1));
                ans += val;
                v[i] -= val;
            }
            while(v[i] != 1){
                ans++;
                int now = i;
                while(now < n){
                    if (now + v[now] >= n){
                        if (v[now] > 1){
                            v[now]--;
                            if (v[now] == 1) st.erase(now);
                        }
                        break;
                    }
                    int pl = v[now];
                    if (v[now] > 1){
                        v[now]--;
                        if (v[now] == 1) st.erase(now);
                    }
                    now = now + pl;
                    if (st.lower_bound(now) == st.end()) break;
                    else now = *st.lower_bound(now);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}