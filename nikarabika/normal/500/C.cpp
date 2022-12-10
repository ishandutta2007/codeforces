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

const int maxn = 500 + 10, maxm = 1000 + 10;
bool mark[maxn];
vector <int> v;
int n, m, r[maxm];
ll w[maxn];
pie ww[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    v.reserve(maxn);
    cin >> n >> m;
    reu(i, 1, n)
        cin >> w[i];
    reu(i, 1, m){
        cin >> r[i];
        if(!mark[r[i]])
            v.insert(v.begin(), r[i]);
        mark[r[i]] = true;
    }
    ll ans = 0;
    reu(i, 1, m){
        int p = v.size() - 1;
        while(v[p] != r[i]){
            ans += w[v[p]];
            p --;
        }
        v.erase(v.begin() + p);
        v.pb(r[i]);
    }
    cout << ans << endl;
    return 0;
}