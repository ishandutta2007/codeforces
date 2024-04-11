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
    string a, b;
    cin >> a >> b;
    int i = 0;
    bool x = 0;
    vector<int> ans(b.size()), pr(b.size());
    for (int j = 0; j < b.size(); j++){
        while(i < a.size() && a[i] != b[j]){
            i++;
        }
        ans[j] = i;
        if (i < a.size()) x = 1;
        i++;
    }
    i = a.size() - 1;
    for (int j = b.size() - 1; j > -1; j--){
        while(i >= 0 && a[i] != b[j]){
            i--;
        }
        pr[j] = i;
        if (i >= 0) x = 1;
        i--;
    }
    if (!x){
        cout << '-';
        return 0;
    }
    int mn = 1e18, st = 0;
    for (int i = 0; i < b.size(); i++){
        if (ans[i] >= a.size()){
            break;
        }
        int l = -1, r = b.size();
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (pr[mid] > ans[i]){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        int now = r - i - 1;
        if (now < mn){
            mn = now, st = i;
        }
    }
    string anss = "";
    for (int i = b.size() - 1; i > -1; i--){
        if (pr[i] < 0) break;
        else{
            anss += b[i];
        }
    }
    if (b.size() - anss.size() < mn){
        reverse(anss.begin(), anss.end());
        cout << anss;
        return 0;
    }
    for (int i = 0; i <= st; i++){
        cout << b[i];
    }
    int l = st, r = b.size();
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (pr[mid] > ans[st]){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    for (int i = r; i < b.size(); i++){
        cout << b[i];
    }
    return 0;
}