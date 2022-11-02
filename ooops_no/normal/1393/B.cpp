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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n), have(N);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        have[v[i]]++;
    }
    int cnt = 0, sup = 0, d = 0;
    for (int i = 0; i < N; i++)
    {
        if (have[i] >= 6)
        {
            sup += have[i];
        }
        else if (have[i] >= 4)
        {
            d += have[i];
        }
        else if (have[i] >= 2)
        {
            cnt += have[i] / 2;
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (have[x] >= 6)
        {
            sup -= have[x];
        }
        else if (have[x] >= 4)
        {
            d -= have[x];
        }
        else if (have[x] >= 2)
        {
            cnt -= have[x] / 2;
        }
        if (c == '+')
        {
            have[x]++;
        }
        else
        {
            have[x]--;
        }

        if (have[x] >= 6)
        {
            sup += have[x];
        }
        else if (have[x] >= 4)
        {
            d += have[x];
        }
        else if (have[x] >= 2)
        {
            cnt += have[x] / 2;
        }
        if (sup + d == 0){
            cout << "NO\n";
        }
        else{
            if (sup == 0){
                if ((d - 4) / 2 + cnt >= 2){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
            else{
                if ((sup > 7) || (d != 0 || cnt != 0)){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}