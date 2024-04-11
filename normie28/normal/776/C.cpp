#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 50;
int n;
ll k, x, s = 0, cnt = 0;
ll d[N] = {};
map <ll, ll> m;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k;
    ll h = 1;
    int lg = 1;
    if (k == 1) lg = 1;
    else if (k == -1) lg = 2;
    else while (h * k <= 1e14)
    {
        h *= k;
        lg++;
    }
    d[0] = 1;
    for (int i = 1; i < lg; i++)
    {
        d[i] = d[i - 1] * k;
    }
    m.insert({0, 1});
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s += x;
        for (int j = 0; j < lg; j++)
        {
            if (m.find(s - d[j]) != m.end()) cnt += m[s - d[j]];
        }
        if (m.find(s) != m.end()) m[s]++;
        else m.insert({s, 1});
    }
    cout << cnt;
}