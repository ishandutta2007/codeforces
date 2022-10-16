#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
bool cmp(pp x, pp y)
{
    if (x.second != y.second)
        return x.second < y.second;
    else
        return x.first < y.first;
}
void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> st[k+1];
    for (int i = 0; i < n; i++) {
        st[a[i]].push_back(b[i]);
    }
    vector<int> pers; int sz = 0;
    for (int i = 1; i <= k; i++) {
        sort(st[i].begin(), st[i].end());

        if (st[i].size()) {
            st[i].pop_back();
            for (int j: st[i]) pers.push_back(j);
        } else {
            sz++;
        }
    }

    long long ans = 0;
    sort(pers.begin(), pers.end());
    for (int i = 0; i < sz; i++) {
        ans += pers[i];
    } 
    cout << ans << '\n';
}
int main()
{
    int testcase = 1;
    //cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}