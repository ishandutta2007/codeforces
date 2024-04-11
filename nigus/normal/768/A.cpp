#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,q,m,k;
ll T;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int c1,c2,c3,c4,c5;
    ll a,b,c,d;

    cin >> n;
    vector<ll> A;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin() , A.end());
    ll mi = A[0];
    ll ma = A[n-1];
    ll ans = 0;

    for(c1 = 0 ;c1 < n; c1++){
        if(A[c1] > mi && A[c1] < ma)ans++;
    }

    cout << ans << "\n";


    return 0;
}