#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll a,b;
    cin >> a >> b;
    if(b-a >= 10){
        cout << 0;
        exit(0);
    }
    ll l = 1;
    for(ll j = a+1;j<=b;j++){
        l*=j;
        l%=10;
    }
    cout << l;
    return 0;
}