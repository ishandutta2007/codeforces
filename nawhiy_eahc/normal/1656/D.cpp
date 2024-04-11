#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n%2 == 1) cout << "2\n";
        else
        {
            ll m = n;
            while(m%2 == 0) m /= 2;
            if(m == 1) cout << "-1\n";
            else
            {
                ll k = n / m;
                if(k - m/2 > 0) cout << m << "\n";
                else cout << m + 2*(k - m/2) - 1 << "\n";
            }
        }
    }
}