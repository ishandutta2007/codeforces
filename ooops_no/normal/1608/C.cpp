#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
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
        vector<int> a(n), b(n), ans(n);
        set<pair<int,int>> sta, stb;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sta.insert({a[i], i});
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
            stb.insert({b[i], i});
        }
        deque<int> q;
        int mxa = *max_element(a.begin(), a.end()), mxb = *max_element(b.begin(), b.end());
        for (int i = 0; i < n; i++){
            if (a[i] == mxa){
                q.pb(i);
                ans[i] = 1;
            }
            if (b[i] == mxb){
                q.pb(i);
                ans[i] = 1;
            }
        }
        while(q.size() > 0){
            int v = q.front();
            q.pop_front();
            while(sta.size() > 0 && (*sta.rbegin()).first > a[v]){
                int i = (*sta.rbegin()).second;
                sta.erase({a[i], i});
                stb.erase({b[i], i});
                if (ans[i] == 0){
                    ans[i] = 1;
                    q.pb(i);
                }
            }
            while(stb.size() > 0 && (*stb.rbegin()).first > b[v]){
                int i = (*stb.rbegin()).second;
                sta.erase({a[i], i});
                stb.erase({b[i], i});
                if (ans[i] == 0){
                    ans[i] = 1;
                    q.pb(i);
                }
            }
        }
        for (int i = 0; i < n; i++){
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}