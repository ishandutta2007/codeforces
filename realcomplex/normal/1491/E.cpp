#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

set<int> F;
vector<pii> T[N];
bool ban[N];
int sub[N];

struct cut{
    int ai;
    int bi;
    int val;
};

vector<cut> lis;

void dfs(int node, int pp, int id){
    sub[node]=1;
    lis.push_back({node, pp, id});
    for(auto x : T[node]){
        if(ban[x.se] || x.fi == pp) continue;
        dfs(x.fi, node, x.se);
        sub[node] += sub[x.fi];
    }
}

bool solve(int node){
    lis.clear();
    dfs(node, -1, -1);
    if(sub[node] <= 3) return true;
    if(!F.count(sub[node])) return false;
    int sz = sub[node];
    bool vi;
    for(auto x : lis){
        if(F.count(sub[x.ai]) && F.count(sz - sub[x.ai])){
            ban[x.val]=true;
            vi = solve(x.ai);
            if(!vi){
                ban[x.val]=false;
            }
            else{
                vi = solve(x.bi);
                if(vi){
                    ban[x.val]=false;
                    return true;
                }
                else{
                    return false;
                }
            }

        }
    }
    return false;
}

int main(){
    fastIO;
    vector<int> f(2);
    f[0] = f[1] = 1;
    int sz = 2;
    while(f[sz - 1] + f[sz - 2] < N){
        f.push_back(f[sz - 1] + f[sz - 2]);
        sz ++ ;
    }
    for(auto x : f){
        F.insert(x);
    }
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(mp(v, i));
        T[v].push_back(mp(u, i));
    }
    bool soln = solve(1);
    if(soln == true)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}