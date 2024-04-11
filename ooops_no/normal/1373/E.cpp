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
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int m = 30;
        string s = "";
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (int v = 0; v <= 9; v++)
                {
                    int ans = 0;
                    for (int ii = 0; ii <= k; ii++)
                    {
                        if (v + ii < 10)
                        {
                            ans += (i - j - 1) * 9 + (v + ii);
                        }
                        else
                        {
                            ans += (v + ii) % 10 + 1;
                        }
                    }
                    if (n < ans)
                    {
                        continue;
                    }
                    if ((n - ans) % (k + 1) != 0)
                    {
                        continue;
                    }
                    else if (v + k < 10)
                    {
                        ans = n - ans;
                        ans /= k + 1;
                        if (ans < j)
                        {
                            continue;
                        }
                        vector<int> lol;
                        for (int k = 0; k < j; k++)
                        {
                            for (int q = 0; q <= 9; q++)
                            {
                                if (ans - q <= (j - k - 1) * 9)
                                {
                                    lol.pb(q);
                                    ans -= q;
                                    break;
                                }
                            }
                        }
                        if (ans != 0) continue;
                        for (int qqq = 0; qqq < (i - j - 1); qqq++)
                        {
                            lol.pb(9);
                        }
                        lol.pb(v);
                        string t = "";
                        for (auto to : lol)
                        {
                            t += to + '0';
                        }
                        if (s == "")
                        {
                            s = t;
                        }
                        else if (t < s)
                        {
                            s = t;
                        }
                    }
                    else
                    {
                        ans = n - ans;
                        ans /= k + 1;
                        if (ans < j)
                        {
                            continue;
                        }
                        else
                        {
                            vector<int> lol;
                            for (int k = 0; k < j - 1; k++)
                            {
                                for (int q = 0; q <= 9; q++)
                                {
                                    if (ans - q <= (j - k - 2) * 9 + 8)
                                    {
                                        lol.pb(q);
                                        ans -= q;
                                        break;
                                    }
                                }
                            }
                            if (j != 0) lol.pb(ans);
                            if (j == 0 && ans != 0) continue;
                            if (ans + 1 > 9) continue;
                            for (int qqq = 0; qqq < (i - j - 1); qqq++)
                            {
                                lol.pb(9);
                            }
                            lol.pb(v);
                            string t = "";
                            for (auto to : lol)
                            {
                                t += to + '0';
                            }

                            if (s == "")
                            {
                                s = t;
                            }
                            else if (t < s)
                            {
                                s = t;
                            }
                        }
                    }
                }
            }
            if (s != "")
            {
                break;
            }
        }
        if (s == "")
        {
            cout << -1 << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}