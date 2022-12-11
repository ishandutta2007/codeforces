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

const int N = (int)2e5 + 9;
bool is[N];
bool isr[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    pii f[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> f[i].fi;
        f[i].se = i + 1;
    }
    sort(f,f + n);
    is[0] = true;
    is[1] = true;
    bool ok;
    for(int i = 2; i < n ; i ++ ){
        ok = true;
        if(f[i].fi - f[i - 1].fi != f[i-1].fi-f[i-2].fi)
            ok = false;
        is[i] = (ok & is[i - 1]);
    }
    isr[n - 1] = true;
    isr[n - 2] = true;
    for(int i = n - 3; i >= 0 ; i -- ){
        ok = true;
        if(f[i + 1].fi - f[i].fi != f[i + 2].fi - f[i + 1].fi)
            ok = false;
        isr[i] = (ok & isr[i + 1]);
    }
    if(n <= 3 || isr[1]){
        cout << f[0].se << "\n";
        exit(0);
    }
    if(is[n-2]){
        cout << f[n-1].se << "\n";
        exit(0);
    }
    for(int i = 1; i < n ; i ++ ){
        if(is[i-1] && isr[i+1]){
            if(i > 1){
                if(f[i + 1].fi - f[i - 1].fi == f[i - 1].fi - f[i - 2].fi){
                    cout << f[i].se << "\n";
                    exit(0);
                }
            }
            else{
                if(f[i + 1].fi - f[i - 1].fi == f[i + 2].fi - f[i + 1].fi){
                    cout << f[i].se << "\n";
                    exit(0);
                }
            }
        }
    }
    cout << -1;
    return 0;
}