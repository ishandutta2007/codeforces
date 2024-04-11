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
    int n;
    cin >> n;
    vector<int> v(n);
    string s;
    cin >> s;
    map<int,int> mp;
    for (int i = 0; i < n; i++){
        v[i] = s[i] - '0';
    }
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == 0){
            ans += cur;
        }
        else{
            int l = i, r = i;
            while(r + 1 < n && v[r + 1] == 1) r++;
            for (int j = 1; j <= r - l + 1; j++){
                cur += (l + j) - mp[j];
                ans += cur;
                mp[j] = r - j + 2;
            }
            i = r;
        }
    }
    cout << ans << endl;
    return 0;
}