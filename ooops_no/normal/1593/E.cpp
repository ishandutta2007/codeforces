#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 4e5 + 10;
vector<int> dp(N);
set<int> g[N];

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
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].insert(b);
            g[b].insert(a);
        }
        if (n <= 2){
            cout << 0 << endl;
        }
        else{
            int have = n;
            set<int> st;
            for (int i = 0; i < n; i++){
                if (g[i].size() == 1){
                    st.insert(i);
                }
            }
            for (int i = 0; i < k && have; i++){
                set<int> stt;
                for (auto to : st){
                    have--;
                    for (auto t : g[to]){
                        g[t].erase(to);
                        if (g[t].size() == 1){
                            stt.insert(t);
                        }
                    }
                }
                st = stt;
            }
            cout << have << endl;
        }
    }
    return 0;
}