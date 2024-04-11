#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> a(N), pr(N);
int n;

bool check(int i){
    if (i == n - 1) return 1;
    if (i & 1){
        return a[i] > a[i + 1];
    }
    else{
        return a[i] < a[i + 1];
    }
}

bool solve(int l, int r){
    if (!check(l) || (l - 1 >= 0 && !check(l - 1))) return 0;
    if (!check(r) || (r - 1 >= 0 && !check(r - 1))) return 0;
    if (l - 2 >= 0){
        if (pr[l - 2] != l - 1) return 0;
    }
    if (pr[n - 1] - pr[r] != n - r - 1) return 0;
    if (l + 2 < r){
        if (pr[r - 2] - pr[l] != (r - (l + 2))) return 0;
    }
    return 1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> bad;
    for (int i = 0; i < n; i++){
        pr[i] = check(i);
        if (pr[i] == 0){
            bad.pb(i);
            bad.pb(i + 1);
        }
        if (i > 0) pr[i] += pr[i - 1];
    }
    sort(bad.begin(), bad.end());
    bad.erase(unique(bad.begin(), bad.end()), bad.end());
    if (bad.size() > 10){
        cout << 0;
        return 0;
    }
    set<pair<int,int>> st;
    int ans = 0;
    for (auto i : bad){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            swap(a[min(i, j)], a[max(i, j)]);
            if (solve(min(i, j), max(i, j))){
                st.insert({min(i, j), max(i, j)});
            }
            swap(a[min(i, j)], a[max(i, j)]);
        }
    }
    cout << st.size() << endl;
    return 0;
}