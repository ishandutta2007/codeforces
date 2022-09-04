#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int n;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif // ONPC
    ll k, a, b;
    cin >> k >> a >> b;
    ll x = a / k, y = b / k;
    a %= k;
    b %= k;
    if (a > 0 && y == 0){
        cout << -1;
        return 0;
    }
    if (b > 0 && x == 0){
        cout << -1;
        return 0;
    }
    cout << x + y;
}