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

int hasz(int len, int za){
    return len * 360 + za;
}

const int nax = 26 * 360;
int par[nax];
int sz[nax];

int f(int x){
    if(par[x] == x) return x;
    return (par[x] = f(par[x]));
}

void u(int x, int y){
    x = f(x);
    y = f(y);
    if(x != y){
        if(sz[x] > sz[y]) swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
    }
}

void clr(){
    for(int i=0;i<nax;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

bool blockedStraight[25][360];
bool blockedCirc[25][360];

void solve(){
    clr();
    for(int i=0;i<25;i++){
        for(int j=0;j<360;j++){
            blockedCirc[i][j] = false;
            blockedStraight[i][j] = false;
        }
    }
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        char c; cin >> c;
        if(c == 'C'){
            int r, k1, k2; cin >> r >> k1 >> k2;
            while(k1 != k2){
                blockedCirc[r][k1] = true;
                k1 += 1;
                k1 %= 360;
            }
        }
        else{
            int r1, r2, k; cin >> r1 >> r2 >> k;
            while(r1 < r2){
                blockedStraight[r1 + 1][k] = true;
                r1 += 1;
            }
        }
    }

    int goal = hasz(23, 69);

    for(int r=1;r<25;r++){
        for(int k=0;k<360;k++){
            if(blockedStraight[r][k] == false){
                int from = hasz(r, (k + 360 - 1) % 360);
                int to = hasz(r, k);
                u(from, to);
            }
        }
    }

    for(int r=1;r<25;r++){
        for(int k=0;k<360;k++){
            if(blockedCirc[r][k] == false){
                int from = hasz(r, k);
                int to = hasz(r + 1, k);
                u(from, to);
            }
        }
    }

    bool ac = false;
    for(int i=0;i<360;i++){
        int from = hasz(1, i);
        ac |= (f(from) == f(goal));
    }
    if(ac) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}