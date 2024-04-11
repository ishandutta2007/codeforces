#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 16005;
vector<int> T[N];
vector<int> R[N];
int n;
void add_edge(int a, int b){
    a += n;
    b += n;
    T[a].push_back(b);
    R[b].push_back(a);
}

vector<int> ord;
bool vis[N];

void dfs1(int node){
    if(vis[node])
        return;
    vis[node]=true;
    for(auto p : T[node])
        dfs1(p);
    ord.push_back(node);
}

int cnt;
int idx[N];

void dfs2(int node){
    if(idx[node]>0)
        return;
    idx[node] = cnt;
    for(auto p : R[node])
        dfs2(p);
}

bool good[N];

void addf(int a, int b){
    add_edge(-a,b);
    add_edge(-b,a);
}

int main(){
    fastIO;
    int m;
    cin >> n >> m;
    int a, b, w;
    for(int i = 0 ; i < m; i ++ ){
        cin >> a >> b >> w;
        if(w == 1){
            addf(-a,b);
            addf(a,-b);
        }
        else{
            addf(a,b);
            addf(-a,-b);
        }
    }

    for(int i = 0; i < 2 * n + 1; i ++ ){
        if(i!=n)
            dfs1(i);
    }
    int nd;
    while(!ord.empty()){
        nd = ord.back();
        ord.pop_back();
        if(idx[nd]==0){
            ++cnt;
            dfs2(nd);
        }
    }
    for(int i = -n; i <= -1; i ++ )
        if(idx[-i + n] == idx[i + n]){
            cout << "Impossible\n";
            return 0;
        }
    vector<int> ans;
    for(int i = -1 ;i >= -n; i -- ){
        if(idx[-i + n] > idx[i + n]){
            ans.push_back(-i);
        }
    }
    cout << ans.size() << "\n";
    for(auto p : ans)
        cout << p << " ";
    return 0;
}