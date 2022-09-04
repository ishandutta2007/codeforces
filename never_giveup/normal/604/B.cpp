#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dl;
typedef long double ld;

ll q[100000];

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    if (k >= n){
        cout << q[n - 1];
        return 0;
    }
    ll l = q[n - 1] - 1, r;
    n = 2 * (n - k);
    r = max(l + 1, q[n - 1] * 2);
    while (r - l > 1){
        ll m = (l + r) / 2;
        bool is = 1;
        for (int i = 0; i < n / 2 && is; i++)
            if (q[i] + q[n - i - 1] > m)
                is = 0;
        if (is)
            r = m;
        else
            l = m;
    }
    cout << r;
}