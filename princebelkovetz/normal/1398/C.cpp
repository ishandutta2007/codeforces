/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#define int long long
using namespace std;

signed main() {
    int tt; cin >> tt;
    
    while (tt --> 0){
        int n; cin >> n;
        string s; cin >> s;
        vector <int> a(n);
        vector <int> pref(n + 1);
        for (int i = 0; i < n; ++i){
            a[i] = s[i] - '0';
            pref[i + 1] = pref[i] + a[i];
        }
        map <int, int> cnt;
        for (int i = 0 ; i <= n; ++i){
            cnt[pref[i] - i]++;
        }
        int ans = 0;
        for (auto x: cnt) 
            ans += x.second * (x.second - 1) / 2;
        cout << ans << '\n';
    }

    return 0;
}