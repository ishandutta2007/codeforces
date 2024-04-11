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
#define ld long double

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
        string s;
        cin >> s;
        if (n % 2 == 1){
            bool x = 0;
            for (int i = 0; i < n; i += 2){
                if ((s[i] - '0') % 2 == 1){
                    x = 1;
                }
            }
            if (!x){
                cout << 2 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
        else{
            bool x = 0;
            for (int i = 1; i < n; i += 2){
                if ((s[i] - '0') % 2 == 0){
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
    }
    return 0;
}