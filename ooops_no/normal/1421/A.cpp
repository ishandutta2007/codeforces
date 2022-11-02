#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, x = 0;
        cin >> a >> b;
        for (int i = 0; i < 30; i++){
            if ((1 << i) & a){
                if ((1 << i) & b){
                    x += (1 << i);
                }
            }
        }
        cout << (a ^ x) + (b ^ x) << endl;
    }
    return 0;
}