#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

const int MOD = 1e9 + 7;

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, ans = 0;
    cin >> n >> x >> y;
    vector<pair<int,int>> v;
    vector<int> anss(n);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.pb({a, -i});
        v.pb({b, i + 1});
        anss[i] = (b - a);
    }
    sort(v.begin(), v.end());
    multiset<int> st;
    for (auto to : v){
        if (to.second <= 0){
            if (st.size() == 0 || (to.first - *st.rbegin()) * y >= x){
                ans += x + y * anss[abs(to.second)];
                ans %= MOD;
            }
            else {
                ans += (to.first - *st.rbegin() + anss[abs(to.second)]) * y;
                ans %= MOD;
                st.erase(st.find(*st.rbegin()));
            }
        }
        else{
            st.insert(to.first);
        }
    }
    cout << ans << endl;
    return 0;
}