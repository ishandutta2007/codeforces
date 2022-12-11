#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int LOG = 30;
int cnt[LOG];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int i = 0 ; i < tc; i ++ ){
        int n;
        cin >> n;
        for(int j = 0 ; j < LOG; j ++ )
            cnt[j] = 0;
        int a;
        for(int j = 0 ; j < n; j ++ ){
            cin >> a;
            for(int k = LOG - 1;k >= 0; k -- ){
                if((a & (1ll << k))){
                    cnt[k] ++ ;
                    break;
                }
            }
        }
        ll answ = 0;
        for(int k = 0 ; k < LOG; k ++ ){
            answ += cnt[k] * 1ll * (cnt[k] - 1) / 2ll;
        }
        cout << answ << "\n";
    }
    return 0;
}