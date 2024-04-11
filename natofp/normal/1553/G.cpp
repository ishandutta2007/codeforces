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

const int nax = 1e6 + 5;
int a[nax];
int n, q;
int d[nax];


void prep(){
    for(int i=1;i<nax;i++) d[i] = i;
    for(int i=2;i<nax;i++){
        if(d[i] == i){
            for(int j=i;j<nax;j+=i){
                if(i < d[j]) d[j] = i;
            }
        }
    }
}

vector<int> primes(int cur){
    vector<int> ans;
    while(cur > 1){
        int di = d[cur];
        if(ans.empty() || ans.back() != di) ans.pb(di);
        cur /= di;
    }
    return ans;
}

int par[nax];
int sz[nax];

int f(int x){
    if(par[x] == x) return x;
    return par[x] = f(par[x]);
}

void u(int x, int y){
    x = f(x);
    y = f(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x];
    par[x] = y;
}

int who[nax];

map<pii, bool> siema;

void solve(){
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i=1;i<=n;i++){
        vector<int> p = primes(a[i]);
        for(int x : p){
            if(who[x] != 0){
                u(who[x], i);
            }
        }
        for(int x : p){
            who[x] = i;
        }
    }

    for(int i=0;i<nax;i++) who[i] = f(who[i]);

    for(int i=1;i<=n;i++){
        int one = a[i];
        int two = one + 1;
        vector<int> p1 = primes(one);
        vector<int> p2 = primes(two);
        for(int x : p1){
            for(int y : p2){
                int c1 = who[x];
                int c2 = who[y];
                if(c1 == 0 || c2 == 0) continue;
                if(c1 != c2){
                    if(c1 > c2) swap(c1, c2);
                    siema[mp(c1, c2)] = true;
                }
            }
        }
        for(int x : p2){
            for(int y : p2){
                int c1 = who[x];
                int c2 = who[y];
                if(c1 == 0 || c2 == 0) continue;
                if(c1 != c2){
                    if(c1 > c2) swap(c1, c2);
                    siema[mp(c1, c2)] = true;
                }
            }
        }
    }

    while(q--){
        int one, two;
        cin >> one >> two;
        if(f(one) == f(two)){
            cout << 0 << "\n";
            continue;
        }
        else{
            int c1 = f(one);
            int c2 = f(two);
            if(c1 > c2) swap(c1, c2);
            if(siema[mp(c1, c2)]) cout << "1" <<"\n";
            else cout<<"2"<<"\n";
        }
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}