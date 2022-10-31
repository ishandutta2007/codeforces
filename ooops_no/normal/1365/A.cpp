#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

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
	while(t--){
        int n, m;
        cin >> n >> m;
        set<int> st, st1;
        for (int i = 0; i < n; i++){
            st.insert(i);
        }
        for (int i = 0; i < m; i++){
            st1.insert(i);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int c;
                cin >> c;
                if (c == 1){
                    st.erase(i);
                    st1.erase(j);
                }
            }
        }
        int sum = min(st.size(), st1.size());
        if (sum % 2 == 0){
            cout << "Vivek" << endl;
        }
        else{
            cout << "Ashish" << endl;
        }
	}
	return 0;
}