#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;
vector<int> T[N]; // potential -> student
int id[N];
int st[N];
bool rem[N];
int rm[N];
int answ[N];
bool vis[N];
int match[N];

void init(){
    for(int i = 0 ; i < N ; i ++ ) vis[i] = false;
}

bool dfs(int u){
    if(vis[u])
        return false;
    vis[u] = true;
    for(auto x : T[u]){
        if(match[x] == -1 || dfs(match[x]) == true){
            match[x] = u;
            return true;
        }
    }
    return false;
}

int main(){
    fastIO;
    for(int i = 0; i < N ; i ++ ){
        match[i] = -1;
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        cin >> st[i];
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> id[i];
    }
    int d;
    cin >> d;
    for(int i = 1; i <= d ; i ++ ){
        cin >> rm[i];
        rem[rm[i]] = true;
    }
    for(int i = 1; i <= n; i ++ ){
        if(!rem[i]){
            T[st[i]].push_back(id[i]);
        }
    }
    int mex = 0;
    while(1){
        init();
        if(dfs(mex)){
            mex ++ ;
        }
        else{
            break;
        }
    }
    answ[d] = mex;
    for(int i = d; i > 1; i -- ){
        T[st[rm[i]]].push_back(id[rm[i]]);
        while(1){
            init();
            if(dfs(mex)){
                mex ++ ;
            }
            else{
                break;
            }
        }
        answ[i-1]=mex;
    }
    for(int i = 1; i <= d; i ++ ){
        cout << answ[i] << "\n";
    }
    return 0;
}