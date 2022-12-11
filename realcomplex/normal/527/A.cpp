#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

ll rez = 0;

ll ans(ll a,ll b){
    if(b>a) swap(b,a);
    if(a<=0||b<=0){
        return 0;
    }
    rez+=a/b;
    return rez+ans(a%b,b);
}

int main(){

    ll a,b;
    cin >> a >> b;
    ans(a,b);
    cout << rez;
    return 0;
}