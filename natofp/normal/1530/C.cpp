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

vector<int> a,b;
int n;

bool ok(int ile){
    int bez = (n + ile) / 4;
    ll suma = 0;
    ll sumb = 0;
    for(int i=0;i<n;i++){
        suma += a[i];
        sumb += b[i];
    }
    suma += ile * 100;
    for(int i=0;i<bez;i++){
        suma -= a[i];
        if(i >= ile){
            sumb -= b[i - ile];
        }
    }
    return suma >= sumb;
}

void solve(){
    cin >> n;
    a.clear(); a.resize(n);
    b.clear(); b.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int lo = 0;
    int hi = n * 3;
    if(ok(0)){
        cout << 0 << "\n";
        return;
    }
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(ok(mid)) hi = mid;
        else lo = mid;
    }
    int ans = hi;
    if(ok(lo)) ans = lo;
    cout << ans << "\n";



}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}