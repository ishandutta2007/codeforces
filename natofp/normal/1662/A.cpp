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

int best[11];

void solve(){
    for(int i=1;i<=10;i++) best[i] = 0;
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int b, d; cin >> b >> d;
        best[d] = max(best[d], b);
    }
    int sum = 0;
    bool ok = true;
    for(int i=1;i<=10;i++){
        if(best[i] == 0) ok = false;
        sum += best[i];
    }
    if(!ok) cout << "MOREPROBLEMS" << "\n";
    else cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}