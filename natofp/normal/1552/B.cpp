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

int a[55555][6];

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) cin >> a[i][j];
    }
    int cand = 1;
    for(int i=2;i<=n;i++){
        int xd = 0;
        for(int j=1;j<=5;j++){
            if(a[i][j] < a[cand][j]) xd++;
        }
        if(xd >= 3) cand = i;
    }

    bool ok = true;
    for(int i=1;i<=n;i++){
        int ac = 0;
        if(i == cand) continue;
        for(int j=1;j<=5;j++){
            if(a[cand][j] < a[i][j]) ac++;
        }
        if(ac <= 2) ok = false;
    }
    if(ok) cout << cand << "\n";
    else cout << -1 << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}