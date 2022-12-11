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

void solve(){
    int n, k;
    cin >> n >> k;
    ll a[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
    }
        int L = 0;
        ll md;
        ll res = (ll)2e9;
        ll xi = 0;
        for(int R = k; R < n; R ++ ){
            md = (a[R] + a[L]) / 2;
            if(max(a[R] - md, md - a[L]) < res){
                res = max(a[R] - md, md - a[L]);
                xi = md;
            }
            L ++ ;
        }
        cout << xi << "\n";
}

int main(){
    fastIO;
    int test_cases;
    cin >> test_cases;
    for(int i = 0 ; i < test_cases ; i ++ ){
        solve();
    }
    return 0;
}