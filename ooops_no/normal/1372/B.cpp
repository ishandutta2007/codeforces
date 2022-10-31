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
            int mx = 0, now = 1e18;
            for (int i = 1; i * i <= n; i++){
                if (n % i == 0){
                    int mem = max(i, n - i);
                    if (mem < now){
                        now = mem;
                        mx = i;
                    }
                    if (i != 1) {
                        mem = max(n / i, n - n / i);
                        if (mem < now){
                            now = mem;
                            mx = n / i;
                        }
                    }
                }
            }
            cout << mx << " " << n - mx << endl;
    }
    return 0;
}