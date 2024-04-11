#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll, ll> > ans;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    ll x;
    cin >> x;
    for (ll n = 1; n <= 10000000; n++){
        ll a = x + (n * (n - 1) * n) / 2 - ((n - 1) * n * (2 * n - 1)) / 6;
        ll b = n * n - ((n - 1) * n) / 2;
        if (a % b == 0){
            ll m = a / b;
            if (n <= m){
                ans.push_back(make_pair(n, m));
                if (n != m)
                    ans.push_back(make_pair(m, n));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
}