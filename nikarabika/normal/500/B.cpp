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

const int maxn = 300 + 10;
vector <int> v[maxn], C[maxn];
int a[maxn], cc[maxn], col = 0;

void dfs(int x){
    cc[x] = col;
    C[col].pb(a[x]);
    rep(i, v[x].size())
        if(cc[v[x][i]] == 0)
            dfs(v[x][i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    reu(i, 1, n)
        cin >> a[i];
    reu(i, 1, n){
        reu(j, 1, n){
            char t;
            cin >> t;
            if(t - 48)
                v[i].pb(j);
        }
    }
    reu(i, 1, n){
        if(cc[i] == 0){
            col ++;
            dfs(i);
        }
    }
    reu(i, 1, col){
        sort(C[i].begin(), C[i].end());
        //reverse(C[i].begin(), C[i].end());
        int p = 0;
        reu(j, 1, n)
            if(cc[j] == i)
                a[j] = C[i][p ++];
    }
    reu(i, 1, n)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}