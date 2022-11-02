#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<deque>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> used(N);
vector<int> d(N);
vector<int> lol;
int n;

void zhfs(int v){
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to]){
            zhfs(to);
            d[v] += d[to];
        }
    }
    d[v]++;
}

void dfs(int v){
    used[v] = 1;
    int mx = 0;
    for (auto to : g[v]){
        if (!used[to]){
            dfs(to);
            mx = max(mx, d[to]);
        }
    }
    if (mx <= n / 2 && n - d[v] <= n / 2){
        lol.pb(v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        lol.clear();
        for (int i = 1; i <= n; i++){
            g[i].clear();
            used[i] = 0;
            d[i] = 0;
        }
        vector<pair<int,int>> kek;
        map<pair<int,int>, int> mp;
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
            kek.pb({a, b});
            mp[{a, b}] = 1;
        }
        zhfs(1);
        for (int i = 1; i <= n; i++) used[i] = 0;
        dfs(1);
        if (lol.size() == 1){
            cout << kek[0].first << " " << kek[0].second << endl;
            cout << kek[0].first << " " << kek[0].second << endl;
        }
        else{
            int st;
            if (d[lol[0]] < d[lol[1]]){
                st = lol[0];
            }
            else{
                st = lol[1];
            }
            while(true){
                int j = -1;
                for (auto to : g[st]){
                    if (j == -1 || d[to] < d[j]){
                        j = to;
                    }
                }
                if (d[j] == 1){
                    if (mp[{j, st}]){
                        cout << j << " " << st << endl;
                    }
                    else{
                        cout << st << " " << j << endl;
                    }
                    st = j;
                    break;
                }
                else{
                    st = j;
                }
            }
            int mem = 0;
            if (d[lol[0]] < d[lol[1]]){
                mem = lol[1];
            }
            else{
                mem = lol[0];
            }
            if (mp[{mem, st}]){
                cout << mem << " " << st << endl;
            }
            else{
                cout << st << " " << mem << endl;
            }
        }
    }
    return 0;
}