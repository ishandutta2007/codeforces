#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

int solve(vector<vector<pair<int,int>>> a){
    deque<int> st;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++){
        assert(is_sorted(st.begin(), st.end()));
        int now = 0;
        for (int j = 0; j < a[i].size(); j++){
            if (a[i][j].second == 1){
                int need = a[i][j].first;
                if (st.size() == 0 || st.front() > need){
                    st.push_front(need);
                    cnt++;
                    continue;
                }
                while(now + 1 < st.size() && st[now + 1] <= need){
                    now++;
                }
                st[now] = need;
            }
        }
        if (i + 1 < a.size()){
            vector<int> kek, ok;
            for (int j = 0; j < a[i + 1].size(); j++){
                ok.pb(a[i + 1][j].first);
            }
            int j = 0;
            for (auto to : st){
                while(j < ok.size() && ok[j] <= to){
                    j++;
                }
                if (j == ok.size()) continue;
                kek.pb(ok[j]);
            }
            st.clear();
            for (auto to : kek) st.pb(to);
        }
    }
    return cnt;
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> c(n, vector<char>(m));
        vector<vector<pair<int,int>>> even, odd;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> c[i][j];
            }
        }
        for (int k = 0; k < m + n - 1; k++){
            int i = 0, j = k;
            vector<pair<int,int>> a;
            if (j >= m){
                i += j - m + 1;
                j = m - 1;
            }
            while(i < n && j >= 0){
                a.pb({i, c[i][j] - '0'});
                i++, j--;
            }
            if ((i + j) % 2 == 0) even.pb(a);
            else odd.pb(a);
        }
        cout << solve(even) + solve(odd) << endl;
    }
    return 0;
}