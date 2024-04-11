#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 4010;
bool has[N][N];
vector<int> T[N];
bool vis[N];
vector<vector<int>> C;

void dfs(int u){
    C.back().push_back(u);
    vis[u]=true;
    for(auto x : T[u]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int n;
int cnt;
int cur;

void go(int node){
    vis[node]=true;
    cnt ++ ;
    for(auto i : C[cur]){
        if(has[node][i] && !vis[i]){
            go(i);
        }
    }
}


bool check(int id){
    for(int i = 1; i <= n; i ++ ){
        has[i][id] ^= 1;
        has[id][i] ^= 1;
        vis[i]=false;
    }
    cnt=0;
    go(id);
    for(int i = 1; i <= n; i ++ ){
        has[i][id] ^= 1;
        has[id][i] ^= 1;
    }
    if(cnt==C[cur].size())return true;
    else return false;

}


void solve(){
    cin >> n;
    char f;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        vis[i]=false;
        for(int j = 1; j <= n; j ++ ){
            cin >> f;
            has[i][j]=f-'0';
            if(has[i][j]){
                T[i].push_back(j);
            }
        }
    }
    C.clear();
    for(int i = 1; i <= n; i ++ ){
        if(!vis[i]){
            C.push_back({});
            dfs(i);
        }
    }
    if(C.size() == 1){
        cout << "0\n";
        return;
    }
    vector<int> L = {-1, -1};
    for(int i = 1; i <= n; i ++ ){
        L.push_back({-1});
    }
    cur = 0;
    int idx;
    for(auto i : C){
        if(i.size() == 1){
            L = i;
            break;
        }
        else{
            idx = -1;
            for(auto j : i){
                if(idx == -1 || T[j].size() < T[idx].size()){
                    idx = j;
                }
            }
            if(T[idx].size() + 1 == i.size()){
                if(i.size() < L.size()){
                    L = i;
                }
            }
            else{
                L = {idx};
                break;
            }
        }
        cur ++ ;
    }
    if(L.size() >= 3 && C.size() >= 3){
        cout << "2\n" << " " << C[0][0] << " " << C[1][0] << "\n";
        return;
    }
    cout << L.size() << "\n";
    for(auto x : L) cout << x << " ";
    cout << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}