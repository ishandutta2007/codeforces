#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double

mt19937 rnd(51);

const int N = 1e5, K = 250;

vector<vector<int>> cycle;
vector<int> ind_cycle(N), ind(N);
vector<set<int>> bad;
vector<int> was(N), tt(N, -1);

void rebuild(vector<int> p){
    int n = p.size();
    cycle.clear();
    bad.clear();
    vector<bool> used(n);
    for (int i = 0; i < n; i++){
        if (!used[i]){
            int now = i, cnt = 0;
            vector<int> b;
            while(!used[now]){
                used[now] = 1;
                b.pb(now);
                ind_cycle[now] = cycle.size();
                ind[now] = cnt++;
                now = p[now];
            }
            cycle.pb(b);
        }
    }
    bad.resize(cycle.size());
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    rebuild(p);
    int cnt = 0;
    for (int i = 0; i < q; i++){
        int t;
        cin >> t;
        if (cnt > K){
            rebuild(p);
            cnt = 0;
        }
        if (t == 1){
            int x, y;
            cin >> x >> y;
            x--, y--;
            swap(p[x], p[y]);
            bad[ind_cycle[x]].insert(ind[x]);
            bad[ind_cycle[y]].insert(ind[y]);
            cnt++;
        }
        else{
            int j, k;
            cin >> j >> k;
            j--;
            bad[ind_cycle[j]].insert(ind[j]);
            cnt++;
            while(1){
                int q = ind_cycle[j];
                if (tt[j] == i){
                    k %= (was[j] - k);
                }
                if (k == 0){
                    cout << j + 1 << '\n';
                    break;
                }
                was[j] = k;
                tt[j] = i;
                if (bad[q].lower_bound(ind[j]) != bad[q].end()){
                    int val = *bad[q].lower_bound(ind[j]);
                    if (val - ind[j] >= k){
                        cout << cycle[q][ind[j] + k] + 1 << '\n';
                        break;
                    }
                    else{
                        k -= val - ind[j] + 1;
                        j = p[cycle[q][val]];
                    }
                }
                else{
                    int val = *bad[q].begin(), m = cycle[q].size();
                    if (val + m - ind[j] >= k){
                        cout << cycle[q][(ind[j] + k) % m] + 1 << '\n';
                        break;
                    }
                    else{
                        k -= val + m - ind[j] + 1;
                        j = p[cycle[q][val]];
                    }
                }
            }
        }
    }
    return 0;
}