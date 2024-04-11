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

const int nax = 2005;
int dp[nax][nax];
ll n, m, k;
const int mod = 1e9 + 7;
const int iv = (int)5e8 + 4;
bool vis[nax][nax];

int f(int rundy, int dodaniaMusi){
    if(rundy == n){
        return 0;
    }
    if(vis[rundy][dodaniaMusi]) return dp[rundy][dodaniaMusi];
    if(dodaniaMusi == 0){
        vis[rundy][dodaniaMusi] = true;
        dp[rundy][dodaniaMusi] = f(rundy + 1, dodaniaMusi);
        return dp[rundy][dodaniaMusi];
    }
    if(dodaniaMusi == n - rundy){
        int res = k + f(rundy + 1, dodaniaMusi - 1);
        res %= mod;
        vis[rundy][dodaniaMusi] = true;
        dp[rundy][dodaniaMusi] = res;
        return res;
    }
    else{
        int g1 = f(rundy + 1, dodaniaMusi); // odjal
        int g2 = f(rundy + 1, dodaniaMusi - 1); // dodal (mniejszy profit here)
        ll res = (g1 + g2);
        res %= mod;
        res *= iv;
        res %= mod;
        vis[rundy][dodaniaMusi] = true;
        dp[rundy][dodaniaMusi] = res;
        return res;
    }
}

void solve(){
    cin >> n >> m >> k;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            vis[i][j] = false;
            dp[i][j] = 0;
        }
    }
    cout << f(0, m) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}