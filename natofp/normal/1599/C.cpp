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

int n;
ll wa;

bool prob(int maps){
    int all = n * (n - 1) * (n - 2) / 6;
    int tri = maps * (maps - 1) * (maps - 2) / 6;
    int bad = n - maps;
    int to = (maps * (maps - 1)) / 2 * bad;
    int ok = tri + to;
    int xdd = maps * (bad * (bad - 1)) / 2;
    ll al = all;
    ll gut = ok;
    gut *= 2;
    gut += xdd;
    return (gut * 10000 >= al * wa * 2);
}

void solve(){
    cin >> n;
    string p; cin >> p;
    while(p.size() < 6) p += "0";
    wa = (p[0] - '0') * 10000 + (p[2]-'0') * 1000 + (p[3]-'0') * 100 + (p[4]-'0') * 10 + (p[5]-'0');
    for(int i=0;i<=n;i++){
        if(prob(i)){
            cout << i << "\n";
            return;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}