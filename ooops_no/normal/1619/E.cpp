#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, zero = 0;
        cin >> n;
        vector<int> a(n);
        map<int,int> cnt;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]]++;
            zero += (a[i] == 0);
        }
        sort(a.begin(), a.end());
        cout << zero << ' ';
        multiset<int> st;
        int j = 0, bad = 0, ans = 0;
        for (int i = 0; i < n; i++){
            while(j < a.size() && a[j] <= i){
                st.insert(a[j++]);
            }
            if (st.size() == 0){
                bad = 1;
            }
            if (bad) {
                cout << -1 << ' ';
                continue;
            }
            ans += i - *st.rbegin();
            st.erase(st.find(*st.rbegin()));
            cout << ans + cnt[i + 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}