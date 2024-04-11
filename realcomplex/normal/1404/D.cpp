#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
const int M = N * 2;
vector<int> T[N];
vector<pii> G[M];

vector<int> soln;
bool vis[M];
bool go[M];
void dfs(int u, bool ff){
    vis[u]=true;
    soln.push_back(u);
    for(auto x : G[u]){
        if(vis[x.fi]) continue;
        if(!ff){
            if(x.se == 0) continue;
        }
        dfs(x.fi, true);
    }
}

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << "First" << endl;
        for(int i = 1; i <= 2 * n; i ++ ){
            if(i <= n)
                cout << i << " ";
            else
                cout << i - n << " ";
        }
        cout << endl;
        int sol;
        cin >> sol;
        return 0;
    }
    else{
        cout << "Second" << endl;
        int p;
        for(int i = 1; i <= 2 * n; i ++ ){
            cin >> p;
            T[p].push_back(i);
        }
        for(int i = 1; i <= n; i ++ ){
            G[T[i][0]].push_back(mp(T[i][1], 0));
            G[T[i][1]].push_back(mp(T[i][0], 0));
            G[i].push_back(mp(i + n, 1));
            G[i + n].push_back(mp(i, 1));
        }
        int sum = 0;
        for(int i = 1; i <= 2 * n; i ++ ){
            if(vis[i]) continue;
            soln.clear();
            dfs(i, false);
            for(int j = 0; j < soln.size(); j += 2){
                go[soln[j]]=true;
                sum += soln[j];
                sum %= 2 * n;
            }
        }
        for(int i = 1; i <= 2 * n; i ++ ){
            if(sum == 0){
                if(go[i]) cout << i << " ";
            }
            else{
                if(!go[i]) cout << i << " ";
            }
        }
        cout << endl;
        int sol;
        cin >> sol;
    }
    return 0;
}