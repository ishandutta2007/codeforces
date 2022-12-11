#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lkd(ll a,ll b){
    if(b == 0){
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

    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    ll md = mkd(x,y);
    cout << (b/md) - ((a-1)/md);
    return 0;
}