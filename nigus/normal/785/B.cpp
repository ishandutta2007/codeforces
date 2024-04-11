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

    cin >> n;
    vector<ll> R1;
    vector<ll> L1;
    vector<ll> R2;
    vector<ll> L2;

    for(c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        L1.push_back(a);
        R1.push_back(b);
    }
    cin >> m;
    for(c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        L2.push_back(a);
        R2.push_back(b);
    }

    sort(R1.begin() , R1.end());
    sort(L1.begin() , L1.end());
    sort(R2.begin() , R2.end());
    sort(L2.begin() , L2.end());

    ll ans = 0;

    ans = max(ans , L2[m-1] - R1[0]);
    ans = max(ans , L1[n-1] - R2[0]);
    cout << ans << "\n";

    return 0;
}