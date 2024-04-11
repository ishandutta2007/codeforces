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
        int x, y;
        cin >> x >> y;
        vector<int> c(7);
        for (int i = 0; i < 6; i++){
            cin >> c[i + 1];
        }
        for (int i = 0; i < 10; i++){
            vector<int> c1(7);
            c1[1] = min(c[1], c[6] + c[2]);
            c1[2] = min(c[2], c[1] + c[3]);
            c1[3] = min(c[3], c[4] + c[2]);
            c1[4] = min(c[4], c[3] + c[5]);
            c1[5] = min(c[5], c[6] + c[4]);
            c1[6] = min(c[6], c[5] + c[1]);
            c = c1;
        }
        if (x == 0){
            if (y >= 0){
                cout << y * c[2];
            }
            else{
                cout << abs(y) * c[5];
            }
        }
        else if (x < 0){
            if (y >= 0){
                cout << c[3] * abs(x) + y * c[2];
            }
            else if (y <= x){
                cout << c[4] * abs(x) + abs(y - x) * c[5];
            }
            else{
                int ans = c[3] * abs(x) + abs(y) * c[5];
                ans = min(ans, c[4] * abs(x) + abs(y - x) * c[2]);
                ans = min(ans, abs(y) * c[4] + abs(abs(x) - abs(y)) * c[3]);
                cout << ans;
            }
        }
        else{
            if (y <= 0){
                cout << x * c[6] + abs(y) * c[5];
            }
            else if (y >= x){
                cout << x * c[1] + abs(y - x) * c[2];
            }
            else{
                int ans = x * c[6] + y * c[2];
                ans = min(ans, x * c[1] + abs(y - x) * c[5]);
                ans = min(ans, y * c[1] + (x - y) * c[6]);
                cout << ans;
            }
        }
        cout << endl;
    }
    return 0;
}