#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back

mt19937 rnd(51);

const int N = 1e6 + 10;
int del[N], a[N], b[N];
vector<pair<int,int>> u[N];
vector<int> add[N], Del[N];


signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; ++i) del[i] = -1;
    for (int i = 2; i < N; ++i){
        if (del[i] == -1){
            del[i] = i;
            if ((ll)i * i < N){
                for (int j = i * i; j < N; j += i){
                    if (del[j] == -1){
                        del[j] = i;
                    }
                }
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i){
        b[i] = (s[i] == '*' ? 1 : -1);
    }
    for (int i = 0; i < n; ++i){
        int val = b[i], now = a[i];
        while (now > 1){
            if (u[del[now]].size() > 0 && u[del[now]].back().first == i){
                u[del[now]].back().second += val;
            }
            else{
                u[del[now]].emplace_back(i, val);
            }
            now /= del[now];
        }
    }
    multiset<int> sp{n};
    for (int i = 0; i < N; i++){
        if (u[i].size() == 0) continue;
        vector<vector<int>> q;
        int s = 0;
        if (u[i][0].first != 0){
            q.pb({-s, 0, u[i][0].first - 1});
        }
        for (int j = 0; j < u[i].size(); j++){
            if (j > 0 && u[i][j - 1].first + 1 <= u[i][j].first - 1){
                q.pb({-s, u[i][j - 1].first + 1, u[i][j].first - 1});
            }
            if (u[i][j].second > 0){
                s += u[i][j].second;
                q.pb({-s + u[i][j].second, u[i][j].first, u[i][j].first});
            }
            else{
                add[u[i][j].first].pb(u[i][j].first);
                Del[u[i][j].first + 1].pb(u[i][j].first);
                s += u[i][j].second;
                while(q.size() > 0 && q.back()[0] + s < 0){
                    add[q.back()[1]].pb(u[i][j].first);
                    Del[q.back()[2] + 1].pb(u[i][j].first);
                    q.pop_back();
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        for (auto to : add[i]){
            sp.insert(to);
        }
        for (auto to : Del[i]){
            sp.erase(sp.find(to));
        }
        ans += *sp.begin() - i;
    }
    cout << ans << endl;
    return 0;
}