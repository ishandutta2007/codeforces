#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int INF = 1e18;

struct Fenwick{
    vector<int> t;
    void build(int n){
        t.resize(n);
    }
    void inc(int i, int d){
        for (; i < t.size(); i = (i | (i + 1))){
            t[i] += d;
        }
    }
    int get(int r){
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ans += t[r];
        }
        return ans;
    }
    int get(int l, int r){
        return get(r) - get(l - 1);
    }
};

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n, ans = INF, cnt = 0;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<deque<int>> pos(26);
        for (int i = 0; i < s.size(); i++){
            pos[s[i] - 'a'].pb(i);
        }
        Fenwick st;
        st.build(n);
        for (int i = 0; i < n; i++){
            int k = t[i] - 'a';
            for (int j = 0; j < k; j++){
                if (pos[j].size() == 0) continue;
                ans = min(ans, cnt + abs(i - (pos[j][0] + st.get(pos[j][0], n - 1))));
            }
            if (pos[k].size() == 0){
                break;
            }
            cnt += abs(i - (pos[k][0] + st.get(pos[k][0], n - 1)));
            st.inc(pos[k][0], 1);
            pos[k].pop_front();
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}