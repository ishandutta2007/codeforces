#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second
#define t abs

ll lkd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return lkd(b,a%b);
    }
}

ll mkd(ll a,ll b){
    return (a*b)/lkd(a,b);
}

int main(){

    ll n;
    cin >> n;
    ll f,s,t;
    if(n == 1){
        cout << 1;
    }
    else if(n == 2){
        cout << 2;
    }
    else if(n == 3){
        cout << 6;
    }
    else{
        if(n%2==1){
            f = n;
            s = n-1;
            t = n-2;
            cout << f*s*t;
        }
        else{
            ll s = 1;
            ll mx = 0;
            for(ll i = max(n-50,s);i<=n;i++){
                for(ll x = max(n-50,s);x<=n;x++){
                    for(ll y = max(n-50,s);y<=n;y++){
                        mx = max(mx,mkd(mkd(i,x),y));
                    }
                }
            }
            cout << mx;
        }
    }
    return 0;
}