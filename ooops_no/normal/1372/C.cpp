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
#include<cassert>
#include <iomanip>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<int, pair<int,int>>, null_type, less<pair<int, pair<int,int>>>, rb_tree_tag, tree_order_statistics_node_update> st;


*/

/*

st.find_by_order();
st.order_of_key();

*/



#define pb push_back
#define ld double

mt19937 rnd(51);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        bool x = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (v[i] != i + 1) x = 1;
        }
        if (!x){
            cout << 0 << endl;
            continue;
        }
        int now = 1, b = n;
        while(now == v[now - 1]){
            now++;
        }
        while(b == v[b - 1]){
            b--;
        }
        x = 0;
        for (int i = now; i <= b; i++){
            if (v[i - 1] == i){
                x = 1;
            }
        }
        if (!x){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}