#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll big = 1000000007ll;
ll n,m,k,x,y;

vector<ll> A;
ll DP[100001] = {0};

ll bs(ll t){
    ll l = 0;
    ll r = n-1;
    if(A[0] > t)return -1;
    while(l < r-1){
        ll mid = (l+r)/2;
        if(A[mid] <= t){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}

ll dp(ll i){
if(i == 0)return 20;
if(i < 0)return 0;
if(DP[i] != -1)return DP[i];
ll ans = big*big;
ans = min(ans , 20+dp(i-1));
ans = min(ans , 50+dp(bs(A[i]-90)));
ans = min(ans , 120+dp(bs(A[i]-1440)));
DP[i] = ans;
return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll c1,c2,c3,c4,c5;
    ll a,b,c;

    cin >> n;

    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        DP[c1] = -1;
        A.push_back(a);
    }
    ll sum = 0;
    for(c1 = 0; c1 < n; c1++){
        cout << dp(c1)-sum  << "\n";
        sum += dp(c1)-sum;
    }

    return 0;
}