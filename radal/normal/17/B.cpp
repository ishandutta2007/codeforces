#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=2e18,maxk = 1e5+20;
const long double eps = 0.0001;
int n;
pll q[N];
vector<int> in[N];
int main(){
    cin >> n;
    rep(i,1,n+1){
        cin >> q[i].X;
        q[i].Y = i;
    }
    sort(q+1,q+n+1);
    int m;
    cin >> m;
    rep(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        in[b].pb(c);
    }
    if (n > 1 && q[n].X == q[n-1].X){
        cout << -1;
        return 0;
    }
    ll ans = 0;
    rep(i,1,n){
        if (in[q[i].Y].empty()){
            cout << -1;
            return 0;
        }
        sort(in[q[i].Y].begin(),in[q[i].Y].end());
        ans += in[q[i].Y][0];
    }
    cout << ans;
    return 0;
}