#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll m = 1e8, k = 0;
    for (int i = 0; i < a; i++){
        ll d;
        cin >> d;
        m = min(m, d);
    }
    for (int i = 0; i < b; i++){
        ll d;
        cin >> d;
        k = max(k, d);
    }
    cout << max(c, c / m * k + c % m);
}