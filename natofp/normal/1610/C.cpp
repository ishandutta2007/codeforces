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
int b[nax];
int n;

bool can(int k){
    int c = 0;
    for(int i=1;i<=n;i++){
        if(c == k) return true;
        if(a[i] >= k - 1 - c && b[i] >= c){
            c += 1;
        }
    }
    return (c == k);
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
    int lo = 0;
    int hi = n;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(can(mid)) lo = mid;
        else hi = mid;
    }
    int ans = lo;
    if(can(hi)) ans = hi;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}