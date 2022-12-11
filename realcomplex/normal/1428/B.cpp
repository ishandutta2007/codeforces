#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
int par[N];
int sz[N];
char in[N];

int fin(int x){
    if(x == par[x]) return x;
    return par[x]=fin(par[x]);
}

void unite(int a, int b){
    a=fin(a);
    b=fin(b);
    if(a==b) return;
    par[a]=b;
    sz[b]+=sz[a];
}

int deg[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i ++ ){
        par[i]=i;
        cin >> in[i];
        deg[i]=0;
        sz[i]=1;
    }
    for(int i = 0 ; i < n; i ++ ){
        if(in[i] == '-')
            unite(i,(i+1)%n);
    }
    int y;
    for(int i = 0 ; i < n; i ++ ){
        y=fin(i);
        if(in[i] == '<')
            deg[y]++;
        if(in[(i+n-1)%n] == '>')
            deg[y] ++ ;
    }
    int sol = 0;
    bool bad = false;
    for(int i = 0 ; i < n; i ++ ){
        if(i == fin(i)){
            if(sz[i]>1)
                sol += sz[i];
            if(deg[i] == 0 || deg[i] == 2){
                bad = true;
            }
        }
    }
    if(!bad){
        cout << n << "\n";
    }
    else{
        cout << sol << "\n";
    }

}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}