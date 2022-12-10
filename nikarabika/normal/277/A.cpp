#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e2 + 10;
int coln[maxn];
vector <int> v[maxn], w[maxn];
int col = 0;

void dfs(int x){
    coln[x] = col;
    rep(i, v[x].size()){
        int lang = v[x][i];
        rep(j, w[lang].size())
            if(!coln[w[lang][j]])
                dfs(w[lang][j]);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    bool x = true;
    reu(i, 1, n){
        int c;
        cin >> c;
        if(c)
            x = false;
        rep(j, c){
            int t;
            cin >> t;
            v[i].pb(t);
            w[t].pb(i);
        }
    }
    if(x){
        cout << n << endl;
        return 0;
    }
    reu(i, 1, n){
        if(!coln[i]){
            col ++;
            dfs(i);
        }
    }
    cout << col - 1 << endl;
	return 0;
}