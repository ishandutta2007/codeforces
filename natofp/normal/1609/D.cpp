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

const int nax = 1005;
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

void init(){
    for(int i=0;i<nax;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

void solve(){
    int n, d; cin >> n >> d;
    vector<pii> s;
    for(int i=1;i<=d;i++){
        int x, y; cin >> x >> y;
        s.pb(mp(x, y));
    }

    for(int i=1;i<=d;i++){
        init();
        int red = 0;
        for(int j=0;j<i;j++){
            pii cur = s[j];
            int x = cur.st;
            int y = cur.nd;
            if(f(x) == f(y)){
                red += 1;
            }
            else u(x, y);
        }
        set<int> was;
        vector<int> v;
        for(int j=1;j<=n;j++){
            int kto = f(j);
            if(was.count(kto) == 0){
                was.insert(kto);
                v.pb(sz[kto]);
            }
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int take = min((int)v.size(), red + 1);
        int sum = 0;
        for(int i=0;i<take;i++){
            sum += v[i];
        }
        sum -= 1;
        cout << sum << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();

    return 0;
}