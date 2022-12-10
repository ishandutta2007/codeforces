#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e2;
int n, m;
set <int> s[maxn];
int col[maxn];
int color = 0;
bool mark[maxn];
vector <int> adj[maxn];

void dfs(int x){
    mark[x] = true;
    rep(i, adj[x].size()){
        if(!mark[adj[x][i]]){
            s[col[x]].insert(adj[x][i]);
            col[adj[x][i]] = col[x];
            if(s[col[x]].size() > 3){
                cout << -1 << endl;
                exit(0);
            }
            dfs(adj[x][i]);
        }
    }
}

bool F(set <int> s, set <int> t){   return (s.size() > t.size());   }

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n >> m;
    rep(i, m){
        int fi, se;
        cin >> fi >> se;
        adj[fi].pb(se);
        adj[se].pb(fi);
    }
    reu(i, 1, n){
        if(!mark[i]){
            col[i] = color;
            s[color++].insert(i);
            dfs(i);
        }
    }
    sort(s, s + color, F);
    int p = 0, q = color - 1;
    while(p < q){
        if(s[p].size() == 3)
            p ++;
        else if(s[p].size() == 2){
            if(s[q].size() == 1){
                s[p ++].insert(*s[q].begin());
                s[q --].clear();
            }
            else{
                cout << -1 << endl;
                exit(0);
            }
        }
        else if(s[p].size() == 1){
            if(q < p + 2){
                cout << -1 << endl;
                exit(0);
            }
            else{
                s[p].insert(*s[q].begin());
                s[p].insert(*s[q].begin());
                s[q --].clear();
            }
        }
    }
    rep(i, p + 1){
        for(__typeof(s[i].begin()) j = s[i].begin(); j != s[i].end(); j ++)
            cout << *j << ' ';
        cout << endl;
    }
	return 0;
}