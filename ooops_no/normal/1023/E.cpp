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

mt19937 rnd(51);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<bool>> used(n, vector<bool>(n));
    int i = 0, j = 0, i1 = n - 1, j1 = n - 1;
    used[i][j] = used[i1][j1] = 1;
    vector<pair<int,int>> a;
    while(abs(i - i1) + abs(j - j1) >= n){
        //cout << i1 << " " << j1 << endl;
        used[i1][j1] = 1;
        a.pb({i1, j1});
        if (i1 == 0){
            j1--;
        }
        else if (j1 == 0){
            i1--;
        }
        else{
            i1--;
            cout << "? " << i + 1 << " " << j + 1 << " " << i1 + 1 << " " << j1 + 1 << endl;
            string s;
            cin >> s;
            if (s == "YES"){
                continue;
            }
            else{
                i1++, j1--;
            }
        }
    }
    used[i1][j1] = 1;
    while(a.size() > 0){
        //cout << i << " " << j << endl;
        i1 = a.back().first, j1 = a.back().second;
        a.pop_back();
        used[i][j] = 1;
        if (i == n - 1){
            j++;
        }
        else if (j == n - 1){
            i++;
        }
        else{
            j++;
            cout << "? " << i + 1 << " " << j + 1 << " " << i1 + 1 << " " << j1 + 1 << endl;
            string s;
            cin >> s;
            if (s == "YES"){
                continue;
            }
            else{
                j--, i++;
            }
        }
    }
    used[i][j] = 1;
    int s = 0, t = 0;
    cout << "! ";
    for (int i = 0; i < 2 * n - 2; i++){
        if (s != n - 1 && used[s + 1][t]){
            cout << "D";
            s++;
        }
        else{
            cout << "R";
            t++;
        }
    }
    return 0;
}