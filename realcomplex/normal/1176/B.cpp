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
    int test_cases;
    cin >> test_cases;
    for(int i = 0 ; i < test_cases; i ++ ){
        int n;
        cin >> n;
        int v[3];
        v[0] = 0, v[1] = 0, v[2] = 0;
        int a;
        for(int i = 0 ; i < n ; i ++ ){
            cin >> a;
            v[a % 3] ++ ;
        }
        int res = v[0];
        int d = min(v[1], v[2]);
        res += d;
        v[1] -= d;
        v[2] -= d;
        res += v[1]/3;
        res += v[2]/3;
        cout << res << "\n";
    }
    return 0;
}