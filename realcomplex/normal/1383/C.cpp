#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 20;
bool e[AL][AL];

int par[AL];
int nx[AL];

int fin(int x){
    if(x == par[x]) return x;
    return par[x]=fin(par[x]);
}

void unite(int a, int b){
    a=fin(a);
    b=fin(b);
    if(a==b)
        return;
    par[a]=b;
}

vector<int> C[AL];
int can[(1<<AL)];
int id[AL];

void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int x, y;
    for(int i = 0; i < AL; i ++ ){
        for(int j = 0; j < AL; j ++ ){
            e[i][j]=false;
        }
        par[i]=i;
        C[i].clear();
    }
    for(int i = 0 ;i < n; i ++ ){
        x = s[i] - 'a';
        y = t[i] - 'a';
        if(x != y){
            e[x][y]=true;
            unite(x,y);
        }
    }
    for(int i = 0 ; i < AL; i ++ ){
        C[fin(i)].push_back(i);
    }
    int m;
    int mask;
    int sol = 0;
    int mx;
    for(int i = 0 ; i < AL; i ++ ){
        if(C[i].size() <= 1) continue;
        m = C[i].size();
        for(int j = 0 ; j < m; j ++ ){
            id[C[i][j]] = j;
            nx[j]=0;
        }
        for(int p = 0 ; p < m ; p ++ ){
            for(int q = 0 ; q < m; q ++ ){
                if(e[C[i][p]][C[i][q]]){
                    nx[p] |= (1 << q);
                }
            }
        }
        for(int j = 0 ; j < (1 << m); j ++ ){
            can[j]=-1;
        }
        can[0]=0;
        mx = 0;
        for(int j = 0 ; j < (1 << m); j ++ ){
            if(can[j] == -1) continue;
            mx = max(mx, __builtin_popcount(j));
            for(int p = 0; p < m ; p ++ ){
                if((j & (1 << p))) continue;
                if((nx[p] & j) && (can[j] & (1 << p))) continue;
                mask = (j | (1 << p));
                can[mask] = (can[j] | nx[p]);
            }
        }
        sol += 2 * (m - mx) + (mx - 1);
    }
    cout << sol << "\n";
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