#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int now = 1;
    map<int,int> mp;
    while(now * now * 2 <= 1e9 + 100){
        mp[now * now * 2] = 1;
        now += 1;
    }
    now = 1;
    while(now * now * 4 <= 1e9 + 100){
        mp[now * now * 4] = 1;
        now++;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (mp[n] ? "YES" : "NO") << endl;
    }
    return 0;
}