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

const int nax = 2e5 + 5;
int a[nax];

void solve(){
    int n, k; cin >> n >> k;
    bool ok = false;
    map<int, int> xd;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) xd[a[i]] += 1;
    for(int i=1;i<=n;i++){
        int s = a[i];
        if(xd[s + k]) ok = true;
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