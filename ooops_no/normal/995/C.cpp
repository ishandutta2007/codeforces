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
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<vector<int>> v(N);
vector<int> ans(N);
vector<int> type(N);

struct pt{
    int x, y;
};

pt add(pt a, pt b){
    return {a.x + b.x, a.y + b.y};
}

pt sub(pt a, pt b){
    return {a.x - b.x, a.y - b.y};
}

int dist(pt a){
    return a.x * a.x + a.y * a.y;
}

void Merge(int a, int b, bool f){
    if (!f){
        if (v[a].size() < v[b].size()) swap(a, b);
        for (auto to : v[b]){
            ans[to] ^= type[b];
            v[a].pb(to);
        }
        v[b].clear();
    }
    else{
        if (v[a].size() > v[b].size()){
            for (auto to : v[b]){
                ans[to] ^= 1;
                ans[to] ^= type[b];
                v[a].pb(to);
            }
            v[b].clear();
        }
        else{
            for (auto to : v[b]){
                ans[to] ^= 1;
            }
            for (auto to : v[a]){
                ans[to] ^= type[a];
                v[b].pb(to);
            }
            v[a].clear();
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++){
        v[i].pb(i);
    }
    int n, val = 1500000ll * 1500000ll;
    cin >> n;
    vector<pt> a(n);
    vector<pair<int, pt>> q;
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++){
        q.pb({i, a[i]});
        if (q.size() > 3) cout << 1 / 0;
        if (q.size() >= 3){
            int val = max({dist(q[0].second), dist(q[1].second), dist(q[2].second)});
            bool x = 0;
            for (int j = 0; j < q.size(); j++){
                for (int k = 0; k < q.size(); k++){
                    if (j == k) continue;
                    if (dist(sub(q[j].second, q[k].second)) <= val){
                        Merge(q[j].first, q[k].first, 1);
                        pt val = sub(q[j].second, q[k].second);
                        q[j].second = q[k].second = val;
                        x = 1;
                        break;
                    }
                    if (dist(add(q[j].second, q[k].second)) <= val){
                        Merge(q[j].first, q[k].first, 0);
                        pt val = add(q[j].second, q[k].second);
                        q[j].second = q[k].second = val;
                        x = 1;
                        break;
                    }
                }
                if (x) break;
            }
            vector<pair<int,pt>> qq;
            for (auto to : q){
                if (v[to.first].size() != 0){
                    qq.pb(to);
                }
            }
            q = qq;
        }
    }
    if (dist(add(q[0].second, q[1].second)) <= val){
        Merge(q[0].first, q[1].first, 0);
    }
    else if (dist(sub(q[0].second, q[1].second)) <= val){
        Merge(q[0].first, q[1].first, 1);
    }
    else if (dist(sub(q[1].second, q[0].second)) <= val){
        Merge(q[1].first, q[0].first, 1);
    }
    else cout << 1 / 0;
    for (auto to : q){
        for (auto t : v[to.first]){
            ans[t] ^= type[to.first];
        }
    }
    for (int i = 0; i < n; i++){
        cout << (ans[i] == 0 ? 1 : -1) << ' ';
    }
    return 0;
}