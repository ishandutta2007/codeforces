#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;



void solve(){
    int n, m;
    cin >> n >> m;
    int r = 0;
    int w = 0;
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        r = max(r, x);
        w = max(w, y);
    }
    if(r + w > n){
        cout << "IMPOSSIBLE" << "\n";
        return;
    }
    r = n - w;
    for(int i=1;i<=r;i++) cout << "R";
    for(int i=1;i<=w;i++) cout << "W";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}