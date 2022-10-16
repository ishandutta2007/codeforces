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
#define mt make_tuple

using namespace std;

const int nax = 2e5 + 5;
ll a[nax];
int n;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        if(a[i] < 0){
            cout << "No" << "\n";
            return;
        }
        if(a[i] == 0) break;
        a[i + 1] += a[i];
        a[i] = 0;
    }
    bool ok = true;
    for(int i=1;i<=n;i++){
        if(a[i] != 0) ok = false;
    }
    if(ok) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}