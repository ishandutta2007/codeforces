#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int c0 = 0, c1 = 0;
    int a;
    for(int i = 0 ; i< n; i ++ ){
        cin >> a;
        if(a%2 == 0) c0 ++ ;
        else c1 ++ ;
    }
    int res = 0;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> a;
        a %= 2;
        a = 1-a;
        if(a == 0){
            if(c0 > 0){
                c0 -- ;
                res ++ ;
            }
        }
        else{
            if(c1 > 0){
                c1 -- ;
                res ++ ;
            }
        }
    }
    cout << res;
    return 0;
}