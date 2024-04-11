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

int gone = 0;




int ask(int id){
    gone += 1;
    cout << "? " << id << endl;
    fflush(stdout);
    int x; cin >> x;
    return x;
}

const int nax = 1e4 + 5;
bool vis[nax];
int p[nax];

void go(int v){
    vector<int> nxt;
    int cur = v;
    int ofset = gone;
    while(1){
        int w = ask(v);
        if(vis[w]) break;
        vis[w] = true;
        nxt.pb(w);
    }
    int len = nxt.size();
    for(int j=0;j<len;j++){
        int v1 = nxt[j];
        int v2 = nxt[(j+1)%len];
        p[v1]=v2;
    }
}

void solve(){
    gone = 0;
    int n; cin >> n;
    fill(vis, vis + n + 1, false);
    for(int i=1;i<=n;i++){
        if(vis[i] == false){
            go(i);
        }
    }
    cout << "! ";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << endl;
    fflush(stdout);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}