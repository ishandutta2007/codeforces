#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll sk){
    return ((sk * (sk - 1)) / 2) + sk;
}

int main()
{
    ll n,m;
    cin >> n >> m;
    if(m >= n){
        cout << n;
    }
    else{
        n = n - m;
        ll s = -1;
        ll e = pow(10,9)*2;
        ll md;
        ll val = pow(10,9)*2;
        val++;
        for(int i = e;i>0;i/=2){
            md = (s+e)/2;
            if(f(md) >= n){
                if(md < val){
                    val = md;
                }
                e = md;
            }
            else{
                s = md;
            }
        }
        cout << val+m;
    }
    return 0;
}