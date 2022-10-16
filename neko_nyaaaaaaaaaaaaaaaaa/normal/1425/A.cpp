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
void solve()
{
    ll n, res = 0;
    cin >> n;
    while (n > 0 )
    {
        if (n % 2 == 0) {
            if (n % 4 == 0 && n > 4) {
                res += 1; n--;
            } else {
                res += n/2; n /= 2;
            }
        } else {
            res += 1, n--;
        }
            
        if (n == 0)
            break;

        if (n % 2 == 0) {
            if (n % 4 == 0 && n > 4) {
                n--;
            } else {
                n /= 2;
            }
        } else {
            n--;
        }
    }
    cout << res << endl;
}
signed main()
{
    fastio;

    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}