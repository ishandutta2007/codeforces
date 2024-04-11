#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e3+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 3e5+20;
ll poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (r*r)%mod*poww(n,k&1)%mod;
}
ll pre[N];
int a[N];
bool mark[N];
int main(){
    int n;
    cin >> n;
    vector<pll> ve;
    rep(i,0,n){
        cin >> a[i];
        if (a[i] < 0) ve.pb({a[i],i});
        if (!i) pre[i] = max(a[i],0);
        else pre[i] = max(pre[i-1],pre[i-1]+a[i]);
    }
    int cnt = n-ve.size(),m = ve.size();
    rep(i,0,m){
        int mi = -2e9,ind = -1;
        rep(j,0,m){
            if (!mark[j] && ve[j].X >= mi){
                mi = ve[j].X;
                ind = j;
            }
        }
        mark[ind] = 1;
        bool f = 1;
        rep(j,ve[ind].Y,n) if (pre[j] < -ve[ind].X) f = 0;
        if (f){
            cnt++;
            rep(j,ve[ind].Y,n) pre[j] += ve[ind].X;
        }
    }
    cout << cnt;
    return 0;
}