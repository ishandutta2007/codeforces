#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int popcount(int x){
    return __builtin_popcount(x);
}

int main(){
    fastIO;
    int x;
    cin >> x;
    int cnt = 0;
    vector<int> res;
    int has;
    while(popcount(x+1) > 1){
        cnt ++ ;
        if(cnt % 2 == 1){
            has= 0;
            for(int i = 25; i >= 0 ; i -- ){
                if(x & (1 << i)){
                    has = 1;
                }
                else{
                    if(has){
                        res.push_back(i+1);
                        x ^= (2 << i) - 1;
                        break;
                    }
                }
            }
        }
        else{
            x ++ ;
        }
    }
    cout << cnt << "\n";
    for(auto x : res)
        cout << x << " ";
    return 0;
}