#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

const int N = 5e5 + 10;
vector<int> v(N);
vector<int> t;

void inc(int i, int d){
    for (; i < t.size(); i = (i | (i + 1))){
        t[i] = max(t[i], d);
    }
    return;
}

int get(int i){
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1){
        ans = max(ans, t[i]);
    }
    return ans;
}

int func(int l, int r, int mn, int mx){
    if (l > r) return 0;
    t.clear();
    t.resize(r - l + 5);
    set<int> st;
    for (int i = l; i <= r; i++){
        st.insert(v[i] - i);
    }
    map<int,int> num;
    int j = 0;
    for (auto to : st){
        num[to] = j++;
    }
    int lol = 0;
    int kek = mn;
    mx -= r - l;
    for (int i = l; i <= r; i++){
        if (v[i] <= kek || v[i] >= mx) {
            kek++;
            mx++;
            continue;
        }
        int dif = num[v[i] - i];
        int here = get(dif) + 1;
        lol = max(lol, here);
        inc(dif, here);
        kek++;
        mx++;
    }
    return r - l + 1 - lol;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> b;
    int ans = 0;
    for (int i = 0; i < k; i++){
        int a;
        cin >> a;
        a--;
        b.pb(a);
        if (i != 0){
            if (b[i] - b[i - 1] > v[b[i]] - v[b[i - 1]]){
                cout << -1;
                return 0;
            }
        }
    }
    if (b.size() == 0){
        cout << func(0, n - 1, -1e18, 1e18);
        return 0;
    }
    if (b[0] != 0){
        ans += func(0, b[0] - 1, -1e18, v[b[0]]);
    }
    for (int i = 0; i < k - 1; i++){
        ans += func(b[i] + 1, b[i + 1] - 1, v[b[i]], v[b[i + 1]]);
    }
    if (b[k - 1] != n - 1){
        ans += func(b[k - 1] + 1, n - 1, v[b[k - 1]], 1e18);
    }
    cout << ans << endl;
    return 0;
}