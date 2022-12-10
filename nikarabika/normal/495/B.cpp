#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

ll a, b;
ll c;

void f(int n){
    if(n > b && n != 1)
        c ++;
    if(1 > b)
        c ++;
    ll i;
    for(i = 2; i * i < n; i ++){
        if(n % i == 0){
            if(i > b)
                c ++;
            if(n / i > b)
                c ++;
        }
    }
    if(i * i == n && i > b)
        c ++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    if(a - b < 0){
        cout << 0 << endl;
        return 0;
    }
    if(a - b == 0){
        cout << "infinity" << endl;
        return 0;
    }
    f(a - b);
    cout << c << endl;
    return 0;
}