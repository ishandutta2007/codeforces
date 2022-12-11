#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;
const int M = 20;
const int S = (1 << M);

int a[N];
int b[N];
bool inq[N];
bool has[S];
int self[S];
vector<int> G[S];
vector<pii> T[S];
map<pii,vector<pii>> E;

bool vis[S];

void dfs(int u){
    vis[u]=true;
    for(auto x : T[u]){
        if(!vis[x.fi]){
            dfs(x.fi);
        }
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i] >> b[i];
    }
    int root = -1;
    bool nah;
    int node;
    int xx, yy;
    pii ash;
    for(int lg = M; lg >= 0 ; lg -- ){
        for(int i = 0 ; i < (1 << lg) ; i ++ ){
            G[i].clear();
            T[i].clear();
            has[i]=false;
            vis[i]=false;
            self[i]=0;
        }
        for(int i = 1; i <= n; i ++ ){
            a[i] = (a[i] & ((1 << lg) - 1));
            b[i] = (b[i] & ((1 << lg) - 1));
            inq[i]=false;
            has[a[i]]=true;
            has[b[i]]=true;
            if(a[i] != b[i]){
                T[a[i]].push_back(mp(b[i], i));
                T[b[i]].push_back(mp(a[i], i));
            }
            else{
                self[a[i]]++;
            }
        }
        root = -1;
        nah = true;
        for(int i = 0 ; i < (1 << lg); i ++ ){
            if(has[i] && !vis[i]){
                if(root == -1) root = i;
                else{
                    nah = false;
                }
                dfs(i);
            }
        }
        if(!nah) continue;
        for(int i = 0 ; i < (1 << lg); i ++ ){
            if(has[i]){
                if(T[i].size() % 2 == 1)
                    nah = false;
            }
        }
        if(!nah) continue;
        vector<int> cur;
        cur.push_back(root);
        vector<int> out;
        int shah;
        while(!cur.empty()){
            node = cur.back();
            shah = false;
            while(!T[node].empty()){
                if(inq[T[node].back().se]){
                    T[node].pop_back();
                }
                else{
                    cur.push_back(T[node].back().fi);
                    inq[T[node].back().se]=true;
                    T[node].pop_back();
                    shah = true;
                    break;
                }
            }
            if(!shah){
                out.push_back(node);
                cur.pop_back();
            }
        }
        vector<int> soln;
        for(auto x : out){
            soln.push_back(x);
            while(self[x]>0){
                soln.push_back(x);
                self[x]--;
            }
        }
        for(int i = 1; i <= n; i ++ ){
            E[mp(a[i],b[i])].push_back(mp(i*2-1,i*2));
            E[mp(b[i],a[i])].push_back(mp(i*2,i*2-1));
        }
        cout << lg << "\n";
        for(int i = 0 ; i + 1 < soln.size(); i ++ ){
            xx = soln[i];
            yy = soln[i+1];
            ash = E[mp(xx,yy)].back();
            E[mp(xx,yy)].pop_back();
            E[mp(yy,xx)].pop_back();
            cout << ash.fi << " " << ash.se << " ";
        }
        cout << "\n";
        return 0;
    }
    return 0;
}