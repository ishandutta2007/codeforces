#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int i = 0 ; i < tc; i ++ ){
        int n, k;
        cin >> n >> k;
        if(n == 1){
            cout << 1 << "\n";
        }
        else{
            ll pwr = 1ll;
            for(int j =0 ; j < k ;j ++ ){
                pwr = (pwr * 1ll * n) % MOD;
            }
            cout << pwr << "\n";
        }
    }
    return 0;
}