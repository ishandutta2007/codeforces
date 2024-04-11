#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=3e6+10,mod = 2e18,inf=1e18;
int cnt[N],a[N],c[N];
ll pre[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    rep(i,1,N){
       for (ll j = 1; j*i < N; j++){
           int r = min(1ll*N-2,i*j);
           if (i == j) c[r] += 1ll*cnt[j]*(cnt[j]-1);
           else c[r] += 1ll*cnt[i]*cnt[j];
       }
    }
    rep(i,1,N-2) pre[i] = pre[i-1]+c[i];
    int m;
    cin >> m;
    rep(i,0,m){
        int p;
        cin >> p;
        cout << 1ll*n*(n-1)-pre[p-1] << endl;

    }
}