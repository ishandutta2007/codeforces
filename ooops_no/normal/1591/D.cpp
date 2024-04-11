#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

struct Fenwick{
    vector<int> t;
    void build(int n){
        t.resize(n);
    }
    int get(int r){
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ans += t[r];
        }
        return ans;
    }
    void inc(int i, int d){
        for (; i < t.size(); i = (i | (i + 1))){
            t[i] += d;
        }
    }
};

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
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> st;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            st.insert(a[i]);
            a[i]--;
        }
        int cnt = 0;
        Fenwick t;
        t.build(n);
        for (int i = 0; i < n; i++){
            cnt += i - t.get(a[i]);
            t.inc(a[i], 1);
        }
        cout << (cnt % 2 == 0 || st.size() != n ? "YES\n" : "NO\n");
    }
    return 0;
}