#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll D = ll(1e9) + 7;
ll ans;
ll dp;

int main(){
    int n;
    cin >> n;
    dp = 0;
    ll P = 1;
    for(int i = 2; i <= n; i++){
        P *= 3;
        P %= D;
        dp = (P - dp + D) % D;
    }
    cout << dp << endl;
    return 0;
}