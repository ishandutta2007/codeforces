#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<int> T[N];
bool kill[N];
int deg[N];
int idx[N];
int p[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
        deg[u] ++ ;
        deg[v] ++ ;
    }
    int sol = 0;
    queue<int> qq;
    for(int i = 1; i <= n; i ++ ){
        if(deg[i] == 1){
            qq.push(i);
        }
        idx[i]=i;
    }
    int node;
    while(!qq.empty()){
        node = qq.front();
        qq.pop();
        for(auto x : T[node]){
            if(!kill[x]){
                deg[x]--;
                if(deg[x]==1)
                    qq.push(x);
            }
        }
        kill[node]=true;
        if(idx[node]!=node) continue;
        for(auto x : T[node]){
            if(!kill[x]){
                swap(idx[node], idx[x]);
                sol += 2;
                break;
            }
        }
        if(idx[node]!=node) continue;
        for(auto x : T[node]){
            swap(idx[node], idx[x]);
            sol += 2;
            break;
        }
    }
    for(int i = 1; i <= n; i ++ )
        p[idx[i]] = i;
    cout << sol << "\n";
    for(int i = 1; i <= n; i ++ ){
        cout << p[i] << " ";
    }
    cout << "\n";
    return 0;
}