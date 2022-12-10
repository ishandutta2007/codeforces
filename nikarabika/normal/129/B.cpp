#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int ans = 0;
const int maxn = 1e2 + 10;
set <int> v[maxn];

void f(queue <int> Q){
    if(Q.empty())
        return;
    queue <int> S;
    bool b = false;
    while(Q.size()){
        int x = Q.front();
        Q.pop();
        if(v[x].size() != 1)
            continue;
        b = true;
        while(v[x].size()){
            int ch = *v[x].begin();
            v[ch].erase(x);
            v[x].erase(v[x].begin());
            if(v[ch].size() == 1)
                S.push(ch);
        }
    }
    if(b)
        ans ++;
    f(S);
}

int main(){
	ios_base::sync_with_stdio(false);
    int n, m;
    queue <int> Q;
    cin >> n >> m;
    rep(i, m){
        int fi, se;
        cin >> fi >> se;
        v[fi].insert(se);
        v[se].insert(fi);
    }
    reu(i, 1, n)
        if(v[i].size() == 1)
            Q.push(i);
    if(Q.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    f(Q);
    cout << ans << endl;
	return 0;
}