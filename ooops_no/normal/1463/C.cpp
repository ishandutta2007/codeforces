#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> t(n), x(n);
        for (int i = 0; i < n; i++){
            cin >> t[i] >> x[i];
        }
        t.pb(1e18);
        int last = 0, now = 0, next = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (last <= t[i]){
                now = next;
                next = x[i];
                last = t[i] + abs(now - next);
                if (t[i + 1] >= last){
                    cnt++;
                }
            }
            else{
                if (last <= t[i + 1]){
                    if (now <= next) now += t[i] - t[i - 1];
                    else now -= t[i] - t[i - 1];
                    if (now <= next){
                        if (now <= x[i] && x[i] <= next){
                            cnt++;
                        }
                    }
                    else{
                        if (next <= x[i] && x[i] <= now){
                            cnt++;
                        }
                    }
                }
                else{
                    if (now <= next){
                        now += t[i] - t[i - 1];
                        if (now <= x[i] && now + t[i + 1] - t[i] >= x[i]){
                            cnt++;
                        }
                    }
                    else{
                        now -= t[i] - t[i - 1];
                        if (now >= x[i] && now - (t[i + 1] - t[i]) <= x[i]){
                            cnt++;
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}