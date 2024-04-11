#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e9;
vector<pll> ind;
int k[N],n;
inline bool check(int pw){
    rep(i,0,n){
        if (ind[i].X > pw) return 0;
        pw += ind[i].Y;
    }
    return 1;
}
inline int bs(){
    int l = 0,r= inf+1,m;
    while (r-l > 1){
        m = (l+r)/2;
        if (check(m)) r = m;
        else l = m;
    }
    return r;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        cin >> n;
        rep(i,0,n){
            cin >> k[i];
            int mx = -1;
            rep(j,0,k[i]){
                int x;
                cin >> x;
                mx = max(mx,x-j+1);
            }
            ind.pb({mx,k[i]});
        }
        sort(ind.begin(),ind.end());
        cout << bs() << endl;
        ind.clear();
    }
}