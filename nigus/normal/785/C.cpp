#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,q,T,k;

ll simu(ll i, ll j){
ll gr = i;
for(ll c1 = 0; c1 < i+2; c1++){
    gr = min(i, gr+j);
    gr -= c1+1;
    if(gr <= 0)return c1+1;
}
}

ll bs(ll i,ll j){
ll l = 0;
ll r = 2000000000;
while(l < r-1){
    ll mid = (l+r)/2;

    if(mid*mid+mid < 2*i-2*j){
        l = mid;
    }
    else{
        r = mid;
    }
}
return r;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c;

    cin >> n >> m;



    m = min(m,ll(n-1));
    cout << m+bs(n,m) << "\n";

    return 0;
}