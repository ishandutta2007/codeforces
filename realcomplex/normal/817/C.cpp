#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum(ll sk){
    ll re = 0;
    while(sk > 0){
        re += sk % 10;
        sk /= 10;
    }
    return re;
}

ll starp(ll sk){
    return sk - sum(sk);
}

ll solve(ll n,ll m){
    ll s = 0;
    ll b = n;
    ll val = (s + b) / 2;
    ll last = n;
    for(ll i = n;i>0;i/=2){
        val = (s + b) / 2;
        if(starp(val) >= m){
            last = val;
            b = val;
        }
        else{
            s = val;
        }
    }
    if(starp(n) >= m){
        last--;
    }
    return last;
}

int main()
{

    ll n,m;
    cin >> n >> m;
    cout << n - solve(n,m);
    return 0;
}