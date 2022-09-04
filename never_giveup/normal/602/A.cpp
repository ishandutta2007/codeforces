#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    ll n, m;
    ll x, y;
    cin >> n >> x;
    ll a[10], b[10];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m >> y;
    for (int j = 0; j < m; j++)
        cin >> b[j];
    ll L = 0, R = 0;
    ll st = 1;
    for (int i = n - 1; i >= 0; i--)
        L += st * a[i], st *= x;
    st = 1;
    for (int i = m - 1; i >= 0; i--)
        R += st * b[i], st *= y;
    if (L > R)
        cout << '>';
    else
    if (L == R)
        cout << '=';
    else
        cout << '<';
}