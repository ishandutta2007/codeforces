#include <bits/stdc++.h>
#define maxn 100001
#define ll long long
#define pp pair<ll,ll>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
struct query
{
    ll l, r, d;
};
ll a[maxn], fen[maxn], m, n, k;
query queries[maxn];
void update(ll pos, ll val)
{
    for (ll i = pos; i <= m; i += i & -i)
        fen[i] += val;
}
ll sum(ll pos)
{
    ll ans = 0;
    for (ll i = pos; i; i -= i & -i)
        ans += fen[i];
    return ans;
}
void update1(ll pos, ll val)
{
    for (ll i = pos; i <= n; i += i & -i)
        a[i] += val;
}
ll sum1(ll pos)
{
    ll ans = 0;
    for (ll i = pos; i; i -= i & -i)
        ans += a[i];
    return ans;
}
void debug()
{
    for (ll i = 1; i <= n; i++)
        cout << sum1(i) << " ";
    cout << endl;
}
int main()
{
    memset(fen, 0, sizeof(fen));
    memset(a, 0, sizeof(a));
    ll x, y, t;
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> t;
        update1(i, t);
        update1(i + 1, -t);
    }

    for  (ll i = 1; i <= m; i++)
        cin >> queries[i].l >> queries[i].r >> queries[i].d;
    for (ll i = 1; i <= k; i++)
    {
        cin >> x >> y;
        update(x, 1);
        update(y + 1, -1);
    }
    for (ll i = 1; i <= m; i++)
    {
        ll temp = sum(i);
        //cout << temp << " ";
        update1(queries[i].l, queries[i].d * temp);
        update1(queries[i].r + 1, -queries[i].d * temp );
        // /debug();
    }
    //cout << endl;
    for (ll i = 1; i <= n; i++)
        cout << sum1(i) << " ";

}