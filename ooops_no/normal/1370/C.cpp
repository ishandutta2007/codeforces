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

mt19937 rnd(51);

bool simple(int v){
    for (int i = 2; i <= sqrt(v); i++){
        if (v % i == 0){
            return 0;
        }
    }
    return 1;
}

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
        if (n == 1){
            cout << "FastestFinger" << endl;
        }
        else{
            if (n == 2){
                cout << "Ashishgup" << endl;
            }
            else if (n % 2 == 1){
                cout << "Ashishgup" << endl;
            }
            else if ((n / 2) % 2 == 0){
                bool x = 0;
                for (int j = 2; j <= sqrt(n); j++){
                    if (n % j == 0 && (j % 2 == 1 || (n / j) % 2 == 1)){
                        x = 1;
                    }
                }
                if (x){
                    cout << "Ashishgup" << endl;
                }
                else{
                    cout << "FastestFinger" << endl;
                }
            }
            else{
                n /= 2;
                if (simple(n)){
                    cout << "FastestFinger" << endl;
                }
                else{
                    cout << "Ashishgup" << endl;
                }
            }
        }
    }
    return 0;
}