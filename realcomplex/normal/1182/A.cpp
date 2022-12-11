#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    int n;
    cin >> n;
    if(n % 2 == 1){
        cout << 0;
    }
    else{
        ll res = 1;
        n /= 2;
        for(int i = 1; i <= n; i ++ )
            res *= 2;
        cout << res;
    }
    return 0;
}