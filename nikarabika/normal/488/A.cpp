#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

ll a, b;

bool check(){
    ll x = a + b;
    x = max(x, (-1) * x);
    while(x > 0){
        if(x % 10 == 8)
            return true;
        x /= 10;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> a;
    for(b = 1; b < 20; b++){
        if(check()){
            cout << b << endl;
            return 0;
        }
    }
    return 0;
}