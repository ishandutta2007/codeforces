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

const int nax = 2e6 + 5;
int cnt[nax];
int pref[nax * 2];
int a[nax];
int n, c;

void solve(){
    cin >> n >> c;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    for(int i=1;i<=c*2;i++){
        pref[i] = pref[i - 1] + cnt[i];
    }
    bool ok = true;
    for(int i=1;i<=c;i++){
        if(cnt[i] == 0) continue;
        int lo = i;
        int hi = i * 2 - 1;
        while(lo <= c){
            int ile = pref[hi] - pref[lo - 1];
            if(ile > 0 & cnt[lo / i] == 0){
                ok = false;
            }
            lo = hi + 1;
            hi = lo + i - 1;
        }
    }
    if(ok) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    for(int i=1;i<=c;i++) cnt[i] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}