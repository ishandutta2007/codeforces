#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

bool solve(int a, int b)
{
    if (__builtin_popcount(b) > __builtin_popcount(a))
    {
        return 0;
    }
    else if (b < a)
    {
        return 0;
    }
    else
    {
        int cnt = 0, cnt1 = 0;
        for (int i = 0; i < 31; i++)
        {
            if (a & (1 << i))
            {
                cnt++;
            }
            if (b & (1 << i)){
                cnt1++;
            }
            if (cnt1 > cnt){
                return 0;
            }
        }
        return 1;
    }
}

bool solve1(int a, int b){
    vector<int> d{a};
    map<int,int> mp;
    while(d.size() > 0){
        int v = d.back();
        d.pop_back();
        for (int i = 1; i <= 1100; i++){
            if ((i & v) == i && !mp[i + v]){
                mp[i + v] = 1;
                d.pb(i + v);
            }
        }
    }
    if (mp[b]) return 1;
    else return 0;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if (solve(a, b)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}