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

const int nax = 3e5 + 5;
int a[nax];
int n;
int poz[nax];
int dd[2][2][nax]; // lewo, prawo // mniejsze, wieksze



int t1[nax][18];
int t2[nax][18];
void build(int n) {
  for(int i = 1; i <= n; ++i){
    t1[i][0] = a[i];
    t2[i][0] = a[i];
  }
  for(int k = 1; k < 18; ++k) {
    for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
      t1[i][k] = min(t1[i][k - 1], t1[i + (1 << (k - 1))][k - 1]);
      t2[i][k] = max(t2[i][k - 1], t2[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int querymin(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return min(t1[l][k], t1[r - (1 << k) + 1][k]);
}

int querymax(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return max(t2[l][k], t2[r - (1 << k) + 1][k]);
}

vector<int> adj[nax];
int dist[nax];
bool vis[nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) adj[i].clear();
    build(n);
    for(int i=1;i<=n;i++) poz[a[i]] = i;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<=n;k++){
                dd[i][j][k] = -1;
            }
        }
    }

    stack<int> male, duze;
    male.push(1); duze.push(1);
    for(int i=2;i<=n;i++){
        while(male.size() && a[male.top()] > a[i]) male.pop();
        while(duze.size() && a[duze.top()] < a[i]) duze.pop();

        if(male.size()) dd[0][0][i] = male.top();
        if(duze.size()) dd[0][1][i] = duze.top();

        male.push(i); duze.push(i);
    }

    while(male.size()) male.pop();
    while(duze.size()) duze.pop();
    male.push(n); duze.push(n);
    for(int i=n-1;i>=1;i--){
        while(male.size() && a[male.top()] > a[i]) male.pop();
        while(duze.size() && a[duze.top()] < a[i]) duze.pop();

        if(male.size()) dd[1][0][i] = male.top();
        if(duze.size()) dd[1][1][i] = duze.top();

        male.push(i); duze.push(i);
    }

    for(int i=1;i<n;i++){
        adj[i].pb(i + 1);
        if(a[i + 1] > a[i]){
            int to = dd[1][0][i];
            if(to == -1) to = n + 1;
            to--;
            int value = querymax(i + 1, to);
            int gd = poz[value];
            adj[i].pb(gd);
        }
        else{
            int to = dd[1][1][i];
            if(to == -1) to = n + 1;
            to--;
            int value = querymin(i + 1, to);
            int gd = poz[value];
            adj[i].pb(gd);
        }
    }

    for(int i=1;i<=n;i++){
        vis[i] = false;
        dist[i] = 1e9;
    }

    vector<int> Q;
    Q.pb(1);
    dist[1] = 0;
    vis[1] = 0;
    int wsk = 0;
    while(wsk < (int)Q.size()){
        int cur = Q[wsk++];
        for(int x : adj[cur]){
            if(!vis[x]){
                vis[x] = true;
                Q.pb(x);
                dist[x] = dist[cur] + 1;
            }
        }
    }
    cout << dist[n] << "\n";



}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}