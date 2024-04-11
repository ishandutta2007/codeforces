#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 1000000007ll;
ll n,m;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll c1,c2,c3,c4,c5;

    cin >> n;

    vector<ll> A;
    for(c1 = 0; c1 < n; c1++){
        cin >> c2;
        A.push_back(c2);
    }

    ll ans = 0;
    sort(A.begin() , A.end());
    for(c1 = 0; c1 < n; c1++){
        ans += A[n-1]-A[c1];
    }
    cout << ans << "\n";

    return 0;
}