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

ll f(ll n){
    return (n*(n+1))/2;
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    if(n == 0) cout << 1;
    else cout << (3*n*(n+1))+1;
    return 0;
}