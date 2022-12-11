#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 510;
const int M = 7000;
int A[N][N];
int k;
vector<pii> E;
int T[M];

int par[N];

int fin(int x){
    if(par[x] == x) return x;
    return par[x]=fin(par[x]);
}

void unite(int a, int b){
    a = fin(a);
    b = fin(b);
    if(a == b) return;
    par[a]=b;
}

vector<int> F[N];

int solve(vector<int> qq){
    if(qq.size() == 1) return qq[0];
    int mx = 0;
    k ++ ;
    int id = k;
    for(auto x : qq){
        par[x] = x;
        F[x].clear();
    }
    for(auto x : qq){
        for(auto y : qq){
            mx = max(mx, A[x][y]);
        }
    }
    T[k]=mx;
    for(auto x : qq){
        for(auto y : qq){
            if(A[x][y] != mx) unite(x, y);
        }
        F[fin(x)].push_back(x);
    }
    int nx;
    for(auto x : qq){
        if(!F[x].empty()){
            nx = solve(F[x]);
            E.push_back(mp(nx, id));
        }
    }
    return id;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> A[i][j];
        }
        T[i] = A[i][i];
    }
    vector<int> ord;
    for(int i = 1; i <= n; i ++ )
        ord.push_back(i);
    k = n;
    int root = solve(ord);
    cout << k << "\n";
    for(int i = 1; i <= k ; i ++ )
        cout << T[i] << " ";
    cout << "\n";
    cout << root << "\n";
    for(auto x : E)
        cout << x.fi << " " << x.se << "\n";
    return 0;
}