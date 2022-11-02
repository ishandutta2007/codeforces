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
const long long int N = 1e5+20,mod = 1e9+7,inf=1e18;
vector<int> ind[N],s[N];
int a[N],cnt[N];
int pre[500][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i];
        if (a[i] <= n) cnt[a[i]]++;
    }
    vector<int> ve;
    rep(i,1,n+1)
        if (i <= cnt[i]) ve.pb(i);
    int sz = ve.size();
    rep(i,0,sz){
        pre[i][0] = (a[0] == ve[i]);
        rep(j,1,n)
            pre[i][j] = pre[i][j-1]+(a[j] == ve[i]);
    }
    while (m--){
        int l,r,ans = 0;
        cin >> l >> r;
        l--;
        if (l){
            rep(i,0,sz)
                if (pre[i][r-1]-pre[i][l-1] == ve[i])
                    ans++;
        }
        else{
            rep(i,0,sz) if (pre[i][r-1] == ve[i])
                ans++;
        }
        cout << ans << endl;
    }
}