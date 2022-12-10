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

const int maxn = 100 + 10;
pie a[maxn];
int col, n;
bool mark[maxn];

void dfs(int x){
    mark[x] = true;
    rep(i, n)
        if(!mark[i])
            if(a[i].p1 == a[x].p1 || a[i].p2 == a[x].p2)
                dfs(i);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n;
    rep(i, n)
        cin >> a[i].p1 >> a[i].p2;
    sort(a, a + n);
    rep(i, n){
        if(!mark[i]){
            col ++;
            dfs(i);
        }
    }
    cout << col - 1 << endl;
	return 0;
}