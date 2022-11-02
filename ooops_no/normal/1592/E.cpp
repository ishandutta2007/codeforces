#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 2e6 + 10;
int ind[2][N];
vector<int> mp[2][N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1), pr(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 19; j >= 0; j--){
        int last = 1;
        for (int i = 1; i <= n; i++){
            mp[i % 2][pr[i - 1]].emplace_back(i);
        }
        for (int i = 1; i <= n; i++){
            if (!(a[i] & (1 << j))){
                last = i + 1;
                continue;
            }
            int inddd = 1 - i % 2;
            while(ind[inddd][pr[i]] < mp[inddd][pr[i]].size() && mp[inddd][pr[i]][ind[inddd][pr[i]]] < last){
                ind[inddd][pr[i]]++;
            }
            if (ind[inddd][pr[i]] < mp[inddd][pr[i]].size()){
                int val = mp[inddd][pr[i]][ind[inddd][pr[i]]];
                ans = max(ans, i - val + 1);
            }
        }
        for (int i = 1; i <= n; i++){
            if (a[i] & (1 << j)) b[i] += (1 << j);
            pr[i] = pr[i - 1] ^ b[i];
        }
        for (int i = 1; i <= n; i++){
            mp[i % 2][pr[i - 1]].clear();
            ind[1 - i % 2][pr[i]] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}