#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
#include<unordered_set>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;

*/
/*

st.find_by_order();
st.order_of_key();

*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> add(8 * N);
vector<int> t(4 * N);

void push(int v){
    t[v] += add[v];
    add[v * 2] += add[v];
    add[v * 2 + 1] += add[v];
    add[v] = 0;
}

void update(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r){
        return;
    }
    if (tl == l && tr == r){
        add[v] += 1;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm));
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int mx(int v, int tl, int tr, int l, int r){
    if (l > r){
        return -1e18;
    }
    push(v);
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(mx(2 * v, tl, tm, l, min(r, tm)), mx(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void func(int v, int tl, int tr, int pos, int val){
    push(v);
    if (tl == tr){
        t[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm){
        func(2 * v, tl, tm, pos, val);
    }
    else{
        func(2 * v + 1, tm + 1, tr, pos, val);
    }
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second.first;
        v[i].second.second = i;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    for (int i = n - 1; i > -1; i--){
        int l = i, r = n;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (v[mid].first - v[i].first < v[i].second.first){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        int ind = l;
        int val = mx(1, 0, n - 1, i, ind);
        ans[v[i].second.second] = val + 1;
        func(1, 0, n - 1, i, val);
        update(1, 0, n - 1, i, n - 1);
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}