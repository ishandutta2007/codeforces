#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

int n, m;

struct Fenwick{
    vector<int> t;
    void build(int a){
        t.resize(a, n + 1);
    }
    void inc(int i, int d){
        for (; i < t.size(); i = (i | (i + 1))){
            t[i] = min(t[i], d);
        }
    }
    int get(int r){
        int val = n + 1;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            val = min(val, t[r]);
        }
        return val;
    }
};

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
        cin >> n >> m;
        vector<int> s(n), pr(n + 1);
        vector<int> u;
        for (int i = 0; i < n; i++){
            cin >> s[i];
            pr[i + 1] = pr[i] + s[i];
        }
        for (auto to : pr){
            u.pb(to);
        }
        sort(u.begin(), u.end());
        u.erase(unique(u.begin(), u.end()), u.end());
        Fenwick t;
        t.build(u.size());
        pair<int,int> p = {0, -1};
        for (int i = n; i >= 1; i--){
            t.inc(lower_bound(u.begin(), u.end(), pr[i]) - u.begin(), i);
            int j = lower_bound(u.begin(), u.end(), pr[i - 1] - m) - u.begin() - 1;
            int r = t.get(j) - 1;
            if (i <= r){
                if (r - i > p.second - p.first){
                    p = {i, r};
                }
            }
        }
        if (p.second == -1) cout << -1 << endl;
        else cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}