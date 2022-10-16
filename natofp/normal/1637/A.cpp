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
    vector<int> a;
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        a.pb(x);
    }
    bool ok = true;
    for(int i=1;i<n;i++){
        if(a[i] < a[i - 1]) ok = false;
    }
    if(ok){
        cout << "NO" << "\n";
    }
    else cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}