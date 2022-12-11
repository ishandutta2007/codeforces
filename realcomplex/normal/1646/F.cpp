#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 100;
int C[N][N];
int cnt[N][N];

int id[N];
int n;

void add(int u, int v, int vl){
    cnt[u][v] += vl;
    id[u] = -1;
    for(int i = 0 ; i < n; i ++ ){
        if(cnt[u][i] > 1){
            id[u] = i;
        }
    }
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            cin >> C[i][j];
            C[i][j] -- ;
            add(i, C[i][j], +1);
        }
    }
    vector<vector<int>> P;
    int fix;
    int jj;
    int las;
    while(1){
        vector<int> d(n,-1);
        fix = -1;
        for(int i = 0 ; i < n; i ++ ){
            if(id[i] != -1) fix = i;
        }
        if(fix == -1) break;
        las = -1;
        for(int y = 0; y < n; y ++ ){
            jj = (fix + y) % n;
            if(id[jj] != -1){
                d[jj] = id[jj];
                las = id[jj];
            }
            else{
                d[jj] = las;
            }
        }
        for(int i = 0 ; i < n; i ++ ){
            add(i, d[i], -1);
            add((i+1)%n, d[i], +1);
        }
        P.push_back(d);
    }
    for(int i = 1 ; i < n; i ++ ){
        for(int j = 0; j < i ; j ++ ){
            vector<int> q;
            for(int v = 0; v < n; v ++ ){
                q.push_back((i + v - j + n) % n);
            }
            P.push_back(q);
            for(int v = 0; v < n; v ++ ){
                add(v, q[v], -1);
                add((v+1)%n, q[v], +1);
            }
        }
    }
    cout << P.size() << "\n";
    for(auto x : P){
        for(auto y : x) cout << y + 1 << " ";
        cout << "\n";
    }
    return 0;
}