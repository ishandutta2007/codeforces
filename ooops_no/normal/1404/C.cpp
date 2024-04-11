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

const int N = 1e6 + 10;
int n, q, t[N];

void inc(int i, int d)
{
    for (; i < n; i = (i | (i + 1)))
    {
        t[i] += d;
    }
    return;
}

int sum(int i)
{
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
    {
        ans += t[i];
    }
    return ans;
}

int sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;
        if (i - v[i] >= 0)
        {
            v[i] = i - v[i];
        }
        else
        {
            v[i] = n;
        }
    }
    vector<vector<pair<int, int>>> take(n);
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        int l = x, r = n - y - 1;
        take[r].pb({l, i});
    }
    for (int i = 0; i < n; i++)
    {
        int l = -1, r = i + 1;
        if (v[i] != n)
        {
            while(r - l > 1)
            {
                int mid = (r + l) / 2;
                if (sum(mid, i) >= v[i]){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            if (l != -1){
                inc(l, 1);
            }
        }
        for (auto to : take[i]){
            ans[to.second] = sum(to.first, i);
        }
    }
    for (auto to : ans){
        cout << to << endl;
    }
    return 0;
}