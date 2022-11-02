#include<bits/stdc++.h>

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

mt19937 rnd(49);

const int N = 1e5 + 10;
vector<int> par(N * 2);
vector<int> sum(N * 2, 1);

int find_set(int v){
    if (par[v] == v) return v;
    else return par[v] = find_set(par[v]);
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a == b){
        return 0;
    }
    if (sum[a] < sum[b]){
        swap(a, b);
    }
    par[b] = a;
    sum[a] += sum[b];
    return 1;
}

bool cmp(const pair<int, pair<int,int>> &a, const pair<int, pair<int,int>> &b){
    return a.second.second < b.second.second;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < N * 2; i++){
        par[i] = i;
    }
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<pair<int, pair<int,int>>> v;
    int sum = 0, cnt = 0;
    for (int i = 0; i < m; i++){
        int s;
        cin >> s;
        for (int j = 0; j < s; j++){
            int bb;
            cin >> bb;
            bb--;
            v.pb({bb + N, {i, a[i] + b[bb]}});
            sum += a[i] + b[bb];
        }
    }
    sort(v.rbegin(), v.rend(), cmp);
    for (auto to : v){
        if (union_set(to.first, to.second.first)){
            cnt += to.second.second;
        }
    }
    cout << sum - cnt << endl;
    return 0;
}