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

const int maxn = 1e5 + 10;
bool mark[maxn];
vector <pie> v[maxn];
vector <int> ans;

bool dfs(int x, int s = 1){
    mark[x] = true;
    bool t = false;
    rep(i, v[x].size())
        if(!mark[v[x][i].p1])
            if(dfs(v[x][i].p1, v[x][i].p2))
                t = true;
    if(t)
        return true;
    if(s == 2){
        ans.pb(x);
        return true;
    }
    return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    rer(i, 1, n){
        int fi, se, t;
        cin >> fi >> se >> t;
        v[fi].pb(mp(se, t));
        v[se].pb(mp(fi, t));
    }
    dfs(1);
    cout << ans.size() << endl;
    rep(i, ans.size())
        cout << ans[i] << ' ';
    cout << endl;
	return 0;
}