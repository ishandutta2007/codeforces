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
    int q;
    cin >> q;
    ll n;
    ll res;
    for(int i = 0 ; i < q; i ++ ){
        cin >> n;
        res = 0;
        while(n % 5 == 0){
            n/=5;
            n*=4;
            res ++ ;
        }
        while(n % 3 == 0){
            n /= 3;
            n *= 2;
            res ++ ;
        }
        while(n % 2 == 0){
            n /= 2;
            res ++ ;
        }
        if(n > 1)
            cout << -1 << "\n";
        else
            cout << res << "\n";
    }
    return 0;
}