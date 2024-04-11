#include<bits/stdc++.h>

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
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.rbegin(), c.rend());
    multiset<int> st;
    for (int i = 0; i <= k; i++){
        st.insert(0);
    }
    int ans = 0;
    for (auto to : c){
        int v = *st.rbegin();
        st.erase(st.find(v));
        ans += v;
        st.insert(v + to);
    }
    cout << ans << endl;
    return 0;
}