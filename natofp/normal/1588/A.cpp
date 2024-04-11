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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool ok = true;
    for(int i=0;i<n;i++){
        if(b[i] != a[i] && b[i] != a[i] + 1) ok = false;
    }
    if(ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}