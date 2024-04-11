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
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(2 * n), col(n);
    for (int i = 0; i < 2 * n; i++){
        cin >> a[i];
        a[i]--;
    }
    deque<pair<int,int>> q;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++){
        col[a[i]]++;
        if (col[a[i]] == 1){
            q.pb({a[i], i});
        }
        else{
            vector<pair<int,int>> b;
            while(q.back().first != a[i]){
                b.pb({q.back().first, q.back().second + 1});
                q.pop_back();
            }
            ans += i - q.back().second - 1;
            q.pop_back();
            for (int i = (int)(b.size()) - 1; i >= 0; i--){
                q.pb(b[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}