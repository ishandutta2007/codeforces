#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)3e5 + 9;
vector<pii> T[N];

int a[N];
int b[N];

int nodes = 0;
bool vis[N];

void dfs(int u, int par){
    vis[u] = true;
    nodes ++ ;
    for(auto x : T[u]){
        if(x.fi == par)
            continue;
        if(!vis[x.fi])
            dfs(x.fi, u);
    }
}

void NO(){
    cout << "-1\n";
    exit(0);
}

int self[N];
bool use[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> q;
    for(int i = 1; i < n; i ++ ){
        cin >> a[i];
        q.push_back(a[i]);
    }
    for(int i = 1; i < n; i ++ ){
        cin >> b[i];
        q.push_back(b[i]);
    }
    sort(q.begin(), q.end());
    q.resize(unique(q.begin(),q.end()) - q.begin());
    for(int i = 1 ; i < n ; i ++ ){
        a[i] = lower_bound(q.begin(),q.end(),a[i]) - q.begin();
        b[i] = lower_bound(q.begin(),q.end(),b[i]) - q.begin();
        if(a[i] > b[i]){
            NO();
        }
        if(a[i] == b[i]){
            self[a[i]] ++ ;
        }
        else{
            T[a[i]].push_back(mp(b[i],i));
            T[b[i]].push_back(mp(a[i],i));
        }
    }
    dfs(0, -1);
    if(nodes != q.size()){
        NO();
    }
    int cnt = 0;
    int id = 0;
    for(int i = 0 ; i < q.size(); i ++ ){
        if(T[i].size() % 2 == 1){
            cnt ++ ;
            id = i;
        }
    }
    if(cnt != 0 && cnt != 2)
        NO();
    vector<int> hlz;
    vector<int> pat;
    int cur;
    hlz.push_back(id);
    while(!hlz.empty()){
        id = hlz.back();
        while(!T[id].empty()){
            if(use[T[id].back().se]){
                T[id].pop_back();
            }
            else{
                break;
            }
        }
        if(T[id].empty()){
            pat.push_back(hlz.back());
            hlz.pop_back();
        }
        else{
            hlz.push_back(T[id].back().fi);
            use[T[id].back().se] = true;
            T[id].pop_back();
        }
    }
    for(auto x : pat){
        self[x] ++ ;
        while(self[x] > 0){
            cout << q[x] << " ";
            self[x] -- ;
        }
    }
    return 0;
}