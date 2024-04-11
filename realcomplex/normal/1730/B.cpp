#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
ld X[N];
ld T[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i ++ ){
        cin >> X[i];
    }
    for(int i = 0; i < n; i ++ ){
        cin >> T[i];
    }
    ld low = 0;
    ld high = (ld)2e8;
    ld mid;
    ld segl,segr;
    segl = segr = 0.0;
    for(int iter = 0; iter < 100; iter ++ ){
        mid = (low + high) / 2.0;
        segl = 0.0;
        segr = (ld)1e9;
        for (int i = 0 ; i < n; i ++ ){
            if(T[i] > mid){
                segl = (ld)1e9 + 1;
            }
            else{
                segl = max(segl, X[i] - (mid - T[i]));
                segr = min(segr, X[i] + (mid - T[i]));
            }
        }
        if(segl <= segr){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    cout << fixed << setprecision(7) << segl << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt ++ ){
        solve();
    }
    return 0;
}