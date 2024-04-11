#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int deg[N];
int par[N];

int idx[N];
int root[N];
vector<int> lf[N];
int cnt;
bool vis[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> par[i];
        deg[par[i]] ++ ;
    }
    int cur;
    for(int i = 1; i <= n; i ++ ){
        if(vis[i]) continue;
        cur = i;
        set<int> vv;
        while(!vis[cur]){
            vv.insert(cur);
            vis[cur] = true;
            cur = par[cur];
        }
        if(vv.count(cur)){
            cnt ++ ;
            root[cnt] = cur;
            for(auto p : vv) idx[p] = cnt;
        }
        else{
            for(auto p : vv) idx[p] = idx[cur];
        }
        if(deg[i] == 0) lf[idx[i]].push_back(i);
    }
    vector<pii> answ;
    for(int i = 2; i <= cnt; i ++ ){
        if(lf[i - 1].empty()) answ.push_back(mp(root[i], root[i - 1]));
        else{
            for(auto p : lf[i - 1])
                answ.push_back(mp(root[i], p));
        }
    }
    if(!lf[cnt].empty())
        for(auto p : lf[cnt])
            answ.push_back(mp(root[1], p));
    else if(cnt != 1)
        answ.push_back(mp(root[1], root[cnt]));
    cout << answ.size() << "\n";
    for(auto p : answ)
        cout << p.fi << " " << p.se << "\n";
    return 0;
}