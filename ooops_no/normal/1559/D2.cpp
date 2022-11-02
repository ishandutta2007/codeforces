#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 1e5 + 10;
map<pair<int,int>, int> pr_a_b;
vector<int> need;
vector<pair<int,int>> now(N);

struct dsu{
    int par[N], sum[N];
    set<int> st[N];
    set<pair<int,int>> bst;
    set<int> have;
    void build(int n){
        for (int i = 0; i < n; i++){
            par[i] = i;
            sum[i] = 1;
            st[i].insert(i);
            bst.insert({1, i});
            have.insert(i);
        }
    }
    int find_set(int v){
        if (v == par[v]) return v;
        else return par[v] = find_set(par[v]);
    }
    void union_set(int a, int b){
        a = find_set(a), b = find_set(b);
        if (a == b) return;
        if (sum[a] < sum[b]){
            swap(a, b);
        }
        par[b] = a;
        have.erase(b);
        sum[a] += sum[b];
        bst.insert({sum[a], a});
        for (auto to : st[b]){
            st[a].insert(to);
            need.pb(to);
        }
        while(bst.size() > 0){
            auto p = *bst.begin();
            if (p.first != sum[p.second] || par[p.second] != p.second){
                bst.erase(p);
            }
            else break;
        }
    }
};

dsu a, b;

void upd(int v){
    pr_a_b[now[v]]--;
    now[v] = {a.find_set(v), b.find_set(v)};
    pr_a_b[now[v]]++;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    a.build(n), b.build(n);
    for (int i = 0; i < n; i++) now[i] = {-1, -1};
    for (int i = 0; i < m1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a.union_set(x, y);
    }
    for (int i = 0; i < m2; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        b.union_set(x, y);
    }
    if (m1 < m2){
        swap(a, b);
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++){
        upd(i);
    }
    while(a.bst.size() > 0){
        int u = a.bst.begin()->second;
        bool x = 0;
        for (auto to : a.st[u]){
            if (a.sum[u] + b.sum[b.find_set(to)] - pr_a_b[now[to]] >= n){
                a.st[u].erase(to);
                x = 1;
                break;
            }
            for (auto t : b.have){
                if (t == b.find_set(to)) continue;
                for (auto tt : b.st[t]){
                    if (a.find_set(tt) != u){
                        a.union_set(to, tt);
                        b.union_set(to, tt);
                        for (auto ttt : need){
                            upd(ttt);
                        }
                        need.clear();
                        ans.pb({to + 1, tt + 1});
                        x = 1;
                        break;
                    }
                }
                if (x) break;
            }
            if (x) break;
        }
        if (!x) a.bst.erase(a.bst.begin());
    }
    cout << ans.size() << endl;
    for (auto to : ans){
        cout << to.first << ' ' << to.second << endl;
    }
    return 0;
}