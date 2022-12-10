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

int n, m;
const int maxn = 1e2 + 10;
int h[maxn];
bool mark[maxn];
vector <int> v[maxn];
ll k, c;

void dfs(int x){
    c ++;
    mark[x] = true;
    rep(i, v[x].size()){
        int u = v[x][i];
        if(!mark[u]){
            h[u] = h[x] + 1;
            dfs(u);
        }
        else if(h[x] - h[u] >= 2)
            k ++;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m){
        int fi, se;
        cin >> fi >> se;
        v[fi].pb(se);
        v[se].pb(fi);
	}
	dfs(1);
	if(c == n && k == 1)
        cout << "FHTAGN!" << endl;
    else
        cout << "NO" << endl;
	return 0;
}