#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<ll, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int F = 105;
int cnt[F];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int t;
    int sum = 0;
    int res = 0;
    int cur;
    int take;
    for(int i = 0 ; i < n; i ++ ){
        cin >> t;
        sum += t;
        res = 0;
        cur = sum - m;
        for(int j = F - 1; j >= 1 ; j -- ){
            if(cur <= 0){
                break;
            }
            if(cnt[j] == 0)
                continue;
            take = min(cnt[j],(cur+j-1)/j);
            res += take;
            cur -= take * j;
        }
        cout << res << " ";
        cnt[t] ++ ;
    }
    return 0;
}