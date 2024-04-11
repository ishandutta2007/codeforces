#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
int a[N],c[N];
list<pair<vector<int>,int>> ve;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i] >> c[i];
        if (ve.empty()){
            vector<int> v;
            v.pb(i);
            ve.insert(ve.begin(),{v,a[i]});
            continue;
        }
        auto it = ve.end();
        it--;
        while (it != ve.begin()){
            if (i == 6) debug(it->Y);
            if (c[i] < (int)(*it).X.size() || (*it).Y > a[i]) break;
            c[i] -= (int)(*it).X.size();
            it--;
        }
        (*it).Y = max(it->Y,a[i]);
        int sz = it->X.size();
        auto pos = (*it).X.end();
        repr(j,sz-1,0){
            if (!c[i] || a[it->X[j]] > a[i])
                break;
            pos--;
            c[i]--;
        }
        (*it).X.insert(pos,i);
        //auto k = it;
        if (sz+1 >= 2*sq){
            int mx1=0,mx2 = 0;
            vector<int> v1,v2;
            rep(j,0,sq){
                int u = (*it).X[j];
                v1.pb(u);
                mx1 = max(mx1,a[u]);
            }
            rep(j,sq,sz+1){
                int u = (*it).X[j];
                v2.pb(u);
                mx2 = max(mx2,a[u]);
            }
            it->Y = mx1;
            it->X.clear();
            for (int u : v1) it->X.pb(u);
            ++it;
            ve.insert(it,{v2,mx2});
        }
    }
    for (auto v = ve.begin(); v != ve.end(); v++){
        for (int u : v->X){
            cout << u+1 << ' ';
        }
    }
}