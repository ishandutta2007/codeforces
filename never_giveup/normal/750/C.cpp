#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

const ll inf = 1e12 + 100;


int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    ll g = 1900;
    int n;
    cin >> n;
    ll l = -inf, r = inf;
    for (int i = 0; i < n; i++){
        int c, d;
        cin >> c >> d;
        if (d == 1)
            l = max(l, g);
        else
            r = min(r, g - 1);
        l += c;
        r += c;
    }
    if (l > r)
        cout << "Impossible";
    else
    if (r > 1e9)
        cout << "Infinity";
    else
        cout << r;
}