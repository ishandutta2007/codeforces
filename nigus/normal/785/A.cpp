#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
int n,m,q,T,k;



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c;

    map<char,ll> M;
    M['T'] = 4;
    M['C'] = 6;
    M['O'] = 8;
    M['D'] = 12;
    M['I'] = 20;
    cin >> n;
    ll ans = 0;
    for(c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;
        ans += M[s[0]];
    }

    cout << ans << "\n";

    return 0;
}