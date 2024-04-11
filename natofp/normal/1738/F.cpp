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
#define mt make_tuple

using namespace std;

const int nax = 1005;
int deg[nax];
int col[nax];
int n;

int par[nax];

int f(int x){
    if(par[x] == x) return x;
    return par[x] = f(par[x]);
}

void u(int x, int y){
    x = f(x);
    y = f(y);
    if(x != y) par[x] = y;
}

int ask(int x){
    cout << "? " << x << endl;
    fflush(stdout);
    int r; cin >> r;
    return r;
}

void ans(){
    cout << "! ";
    for(int i=1;i<=n;i++) cout << col[i] << " ";
    cout << endl;
    fflush(stdout);
}

void skoncz(int skladowa, int kolor){
    for(int i=1;i<=n;i++){
        if(f(i) == skladowa) col[i] = kolor;
    }
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> deg[i];
    for(int i=1;i<=n;i++) par[i] = i;
    for(int i=1;i<=n;i++) col[i] = 0;
    int done = 0;
    int c = 0;
    while(done < n){
        int id = -1;
        int mx = -1;
        for(int i=1;i<=n;i++){
            if(col[i] == 0 && deg[i] > mx){
                mx = deg[i];
                id = i;
            }
        }
        ++c;
        col[id] = c;
        done++;
        for(int q=0;q<deg[id];q++){
            int go = ask(id);
            u(go, id);
            if(col[go] != 0){
                skoncz(f(go), col[go]);
                break;
            }
            else{
                col[go] = col[id];
                done++;
            }
        }
    }
    ans();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}