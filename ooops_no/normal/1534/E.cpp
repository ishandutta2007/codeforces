#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> d(n + 1, 1e18), par(n + 1, -1), col(n + 1);
    d[0] = 0;
    deque<int> q{0};
    while(q.size() > 0){
        int v = q.front();
        q.pop_front();
        if (v + k <= n && d[v + k] == 1e18){
            d[v + k] = d[v] + 1;
            par[v + k] = v;
            q.pb(v + k);
        }
        for (int i = 1; i <= k; i++){
            if (v >= i && v - i + k <= n && d[v - i * 2 + k] == 1e18){
                d[v - i * 2 + k] = d[v] + 1;
                par[v - i * 2 + k] = v;
                q.pb(v - i * 2 + k);
            }
        }
    }
    if (par[n] == -1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> have;
    int nn = n;
    while(n != -1){
        have.pb(n);
        n = par[n];
    }
    n = nn;
    reverse(have.begin(), have.end());
    int ans = 0;
    for (int i = 0; i + 1 < have.size(); i++){
        int now = have[i], nw = have[i + 1];
        for (int j = 0; j <= k; j++){
            if (now - 2 * j + k == nw){
                int need = j;
                vector<int> show;
                for (int f = 1; f <= n; f++){
                    if (col[f] % 2 == 1 && need){
                        need--;
                        show.pb(f);
                    }
                }
                need = k - j;
                for (int f = 1; f <= n; f++){
                    if (col[f] % 2 == 0 && need){
                        need--;
                        show.pb(f);
                    }
                }
                cout << "? ";
                for (auto to : show){
                    cout << to << ' ';
                    col[to] ^= 1;
                }
                cout << endl;
                int val;
                cin >> val;
                ans ^= val;
            }
        }
    }
    cout << "! " << ans << endl;
    return 0;
}