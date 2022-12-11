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
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i ++ ){
        ll n, k;
        cin >> n >> k;
        ll res = 0;
        while(n > 0){
            if(n % k == 0){
                n /= k;
                res ++ ;
            }
            else{
                res += n % k;
                n -= n % k;
            }
        }
        cout << res << "\n";
    }
    return 0;
}