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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, m, sum = 0, ans = 0, cnt = 0;
    cin >> n >> d >> m;
    vector<int> v, v1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > m)
        {
            v.pb(a);
        }
        else
        {
            v1.pb(a);
            sum += a;
        }
    }
    sort(v.rbegin(), v.rend());
    sort(v1.rbegin(), v1.rend());
    for (int i = 1; i < v1.size(); i++){
        v1[i] = v1[i - 1] + v1[i];
    }
    ans = sum;
    int j = v1.size() - 1;
    for (int i = 0; i < v.size(); i++)
    {
        cnt += v[i];
        int need = i * d;
        if (need > n - i - 1) break;
        if (v1.size() == 0){
            ans = max(ans, cnt);
            continue;
        }
        if (n - i * (d + 1) - 2 < 0){
            ans = max(ans, cnt);
            continue;
        }
        ans = max(ans, cnt + v1[min((int)v1.size() - 1, n - i * (d + 1) - 2)]);
    }
    cout << ans << endl;
    return 0;
}