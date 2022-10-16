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

int cnt[222];

void solve(){
    int n; cin >> n;
    fill(cnt, cnt + 222, 0);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        x = abs(x);
        cnt[x] += 1;
    }
    int ac = 0;
    for(int i=1;i<222;i++){
        ac += min(cnt[i], 2);
    }
    if(cnt[0]) ac += 1;
    cout << ac << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}