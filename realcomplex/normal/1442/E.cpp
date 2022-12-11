#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int col[N];
int deg[N];
bool kill[N];
vector<int> T[N];
int n;
queue<int> emp[3];

void delet(int cl){
    int node;
    while(!emp[cl].empty()){
        node = emp[cl].front();
        emp[cl].pop();
        if(kill[node]) continue;
        for(auto x : T[node]){
            if(kill[x]) continue;
            deg[x] -- ;
            if(deg[x] == 1){
                emp[col[x]].push(x);
            }
        }
    }
}

void clean(queue<int> &shit){
    while(!shit.empty()) shit.pop();
}

int get(int f){
    clean(emp[0]);
    clean(emp[1]);
    clean(emp[2]);
    for(int i = 1; i <= n; i ++ ){
        deg[i]=T[i].size();
        kill[i]=false;
        if(deg[i] == 1) // guranteed to not be empty
            emp[col[i]].push(i);
    }
    int node;
    int sol = 0;
    while(!emp[0].empty() || !emp[1].empty() || !emp[2].empty()){
        while(!emp[f].empty() || !emp[0].empty()){
            delet(f);
            delet(0);
        }
        sol ++ ;
        if(f == 1) f = 2;
        else f = 1;
    }
    return sol;
}

void solve(){
    cin >> n;
    bool shit = true;
    for(int i = 1; i <= n; i ++ ){
        cin >> col[i];
        if(i > 1 && col[i] != col[i - 1]) shit = false;
        T[i].clear();
    }
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    if(shit){ // dumb cases
        cout << "1\n";
        return;
    }
    cout << min(get(1), get(2)) << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}