#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

int check(string s, string t){
    int j = 0, n = s.size(), m = t.size();
    for (int i = 0; i < m; i++){
        if (j < n && t[i] == s[j]){
            j++;
        }
    }
    int ans = m - j + (n - j);
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v{1};
    int now = 1;
    while(now < 1e18){
        now *= 2;
        v.pb(now);
    }
    int t;
    cin >> t;
    while(t--){
        int n, ans = 1e18;
        cin >> n;
        for (auto to : v){
            ans = min(ans, check(to_string(to), to_string(n)));
        }
        cout << ans << endl;
    }
    return 0;
}