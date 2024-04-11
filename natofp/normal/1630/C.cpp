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

const int nax = 3e5 + 5;
int a[nax];
int n;
int lft[nax];
int rgt[nax];

int ans = 0;

void solve(int s){
    if(s > n) return;
    if(rgt[a[s]] == s){
        solve(s + 1);
        return;
    }
    int e = rgt[a[s]];
    int kto = -1;
    int R = -1e9;
    for(int i=s+1;i<e;i++){
        int v = a[i];
        if(rgt[v] > e){
            if(rgt[v] > R){
                R = rgt[v];
                kto = i;
            }
        }
    }
    if(kto == -1){
        ans += (e - s - 1);
        solve(e + 1);
        return;
    }
    ans += (kto - s - 1);
    solve(kto);
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    fill(lft,lft+n+1,1e9);
    fill(rgt,rgt+n+1,-1e9);
    for(int i=1;i<=n;i++){
        int v = a[i];
        lft[v] = min(lft[v], i);
        rgt[v] = max(rgt[v], i);
    }
    solve(1);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}