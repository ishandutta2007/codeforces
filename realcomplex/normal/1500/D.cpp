#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int N = 1510;
int C[N][N];
int en[N][N];

vector<pii> low[N][N];
const int M = N * N;


bool use[M];

int lim;


vector<int> pos[M];
int ip[M];

vector<int> ele[M];
int ic[M];

int cnt[M]; // how many are i
int cum = 0;


void upd(int id, int v){
    if(ic[id] >= ele[id].size())
        return;
    if(ele[id][ic[id]] <= lim){
        cum += v;
    }
    cnt[ele[id][ic[id]]] += v;
}


void push(int x, int y){
    upd(x, -1);
    pos[x].push_back(y);
    while(ele[x].size() > ic[x] && ele[x].back() > y){
        ele[x].pop_back();
    }
    ele[x].push_back(y);
    upd(x, +1);
}

void pop(int x){
    upd(x, -1);
    int las = pos[x][ip[x]];
    ip[x] ++ ;
    if(ele[x][ic[x]] == las)
        ic[x] ++ ;
    upd(x, +1);
}

int sol[N];


int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> C[i][j];
        }
    }
    int en;
    int dist;
    for(int i = n; i >= 1; i -- ){
        for(int j = n; j >= 1; j -- ){
            low[i][j].push_back(mp(i, C[i][j]));
            use[C[i][j]]=true;
            for(auto x : low[i + 1][j]){
                if(!use[x.se]){
                    use[x.se]=true;
                    low[i][j].push_back(x);
                }
            }
            for(auto x : low[i][j])
                use[x.se]=false;
            while(low[i][j].size() > q + 1) low[i][j].pop_back();
        }
        en = n;
        lim = i;
        cum = 0;
        for(int j = n ; j >= 1; j -- ){
            for(auto x : low[i][j]){
                push(x.se, x.fi);
            }
            while(cum > q){
                for(auto x : low[i][en]){
                    pop(x.se);
                }
                cum -= cnt[lim];
                en--;
                lim -- ;
            }
            lim ++ ;
            cum += cnt[lim];
            dist = (en - j + 1);
            dist = min(dist, n - i + 1);
            dist = min(dist, n - j + 1);
            sol[1]++;
            sol[dist+1]--;
        }
        for(int j = 1; j <= n; j ++ ){
            for(auto x : low[i][j]){
                cnt[x.fi]=0;
                pos[x.se].clear();
                ip[x.se] = 0;
                ele[x.se].clear();
                ic[x.se] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        sol[i] += sol[i - 1];
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}