#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

vector<pii> E[N];
int dir[N];

bool valid = true;

void dfs(int node){
    for(auto x : E[node]){
        if(dir[x.se] == -1){
            dir[x.se] = (dir[node]^1);
            dfs(x.se);
        }
        else{
            if(dir[x.se] == dir[node]){
                valid = false;
            }
        }
    }
}

vector<int> T[N];

int state[N];
vector<int> ord;


void dfs1(int node){
    if(state[node] == 1){
        valid=false;
        return;
    }
    if(state[node] == 2){
        return;
    }
    state[node]=1;
    for(auto x : T[node]){
        dfs1(x);
    }
    state[node]=2;
    ord.push_back(node);
}

int pos[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    int ii, jj;
    int typ;
    for(int i = 1; i <= n; i ++ ){
        dir[i] = -1;
    }
    for(int i = 1; i <= m; i ++ ){
        cin >> typ >> ii >> jj;
        E[ii].push_back(mp(typ, jj));
        E[jj].push_back(mp(typ, ii));
    }
    for(int i = 1; i <= n; i ++ ){
        if(dir[i] == -1){
            dir[i] = 0;
            dfs(i);
        }
    }
    if(!valid){
        cout << "NO\n";
        return 0;
    }
    for(int i = 1; i <= n; i ++ ){
        if(dir[i] == 0){ // i is left
            for(auto x : E[i]){ // x is right
                if(x.fi == 1){
                    T[i].push_back(x.se); // xi < x_x
                }
                else{
                    T[x.se].push_back(i);
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        dfs1(i);
    }
    reverse(ord.begin(), ord.end());
    if(!valid){
        cout << "NO\n";
        return 0;
    }
    for(int i = 0 ; i < ord.size(); i ++ ){
        pos[ord[i]] = i;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i ++ ){
        if(dir[i] == 0) cout << "L ";
        else cout << "R ";
        cout << pos[i] << "\n";
    }
    return 0;
}