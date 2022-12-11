#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 10;
const int M = N * 4;

vector<int> E[N];

int par[N];
int tin[N];
int tout[N];
int tt;

void dfs(int u, int pa){
    par[u] = pa;
    tt ++ ;
    tin[u] = tt;
    for(auto x : E[u]){
        if(x == pa) continue;
        dfs(x, u);
    }
    tout[u] = tt;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

char can[N][2];
vector<int> T[M];
vector<int> R[M];


bool vis[M];
vector<int> ord;

void dfs0(int u){
    vis[u]=true;
    for(auto x : T[u]){
        if(vis[x]) continue;
        dfs0(x);
    }
    ord.push_back(u);
}

int idx[M];
int idc;

void dfs1(int u){
    vis[u]=true;
    idx[u]=idc;
    for(auto x : R[u]){
        if(vis[x]) continue;
        dfs1(x);
    }
}

int n, q;

int get_id(int node, int bit){
    return node + bit * n;
}

int get_q(int ids, int bit){
    return n * 2 + ids + q * bit;
}

void add_edge(int u, int v){
    T[u].push_back(v);
    R[v].push_back(u);
}

void add_or(int a1, int a0, int b1, int b0){
    add_edge(a0, b1);
    add_edge(b0, a1);
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    cin >> n >> q;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, -1);
    string st;
    vector<int> lis, qa;
    int pi, qi;
    for(int i = 1; i <= n; i ++ )
        can[i][0] = can[i][1] = '#';
    int gg;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> u >> v >> st;
        lis.clear();
        qa.clear();
        while(!is_anc(u, v)){
            lis.push_back(u);
            u = par[u];
        }
        lis.push_back(u);
        while(!is_anc(v, u)){
            qa.push_back(v);
            v = par[v];
        }
        reverse(qa.begin(), qa.end());
        for(auto x : qa) lis.push_back(x);
        for(int i = 0 ; i < st.size(); i ++ ){
            pi = i;
            qi = st.size() - i - 1;
            if(can[lis[pi]][0] == '#'){
                can[lis[pi]][0] = st[pi];
                can[lis[pi]][1] = st[qi];
            }
        }
        for(int i = 0 ; i < st.size(); i ++ ){
            gg = -1;
            for(int j = 0 ; j < 2; j ++ ){
                if(can[lis[i]][j] == st[i]) gg = j;
            }
            if(gg == -1){
                //cout << "Q: " << iq << " " << "Q: " << iq << "\n";
                add_or(get_q(iq, 1), get_q(iq, 0), get_q(iq, 1), get_q(iq, 0));
            }
            else{
                //cout << "Q: " << iq << " " << "N: " << lis[i] << " " << can[lis[i]][gg] << "\n";
                add_or(get_q(iq, 1), get_q(iq, 0), get_id(lis[i], gg), get_id(lis[i], 1-gg));
            }
            gg = -1;
            for(int j = 0 ; j < 2; j ++ ){
                if(can[lis[i]][j] == st[st.size() - i - 1]) gg = j;
            }
            if(gg == -1){
                //cout << "!Q: " << iq << " " << "!Q: " << iq << "\n";
                add_or(get_q(iq, 0), get_q(iq, 1), get_q(iq, 0), get_q(iq, 1));
            }
            else{
                //cout << "!Q: " << iq << " " << "N: " << lis[i] << " " << can[lis[i]][gg] << "\n";
                add_or(get_q(iq, 0), get_q(iq, 1), get_id(lis[i], gg), get_id(lis[i], 1-gg));
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        if(can[i][0] == '#')
            can[i][0] = can[i][1] = 'a';
        //cout << can[i][0] << " " << can[i][1] << "\n";
    }
   // cout << "----\n";
    for(int i = 1; i <= 2 * (n + q); i ++ ){
        if(!vis[i]){
            dfs0(i);
        }
    }
    for(int i = 1; i <= 2 * (n + q); i ++ ) vis[i] = false;
    int node;
    while(!ord.empty()){
        node = ord.back();
        ord.pop_back();
        if(vis[node]) continue;
        idc ++ ;
        dfs1(node);
    }
    for(int i = 1; i <= q; i ++ ){
        if(idx[n * 2 + i] == idx[n * 2 + q + i]){
            cout << "NO\n";
            return 0;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        if(idx[i] == idx[i + n]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    for(int i = 1; i <= n; i ++ ){
        if(idx[i] > idx[i + n]){
            cout << can[i][0];
        }
        else{
            cout << can[i][1];
        }
    }
    return 0;
}