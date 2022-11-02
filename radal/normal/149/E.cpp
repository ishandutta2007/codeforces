#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int f[N],pre[N],f2[N];
int main(){
    int n,m;
    string s;
    cin >> s >> m;
    n = s.size();
    f[0] = 0;
    int k,cnt = 0;
    rep(j,0,m){
        k = 0;
        string t,w2,w;
        cin >> t;
        if (t.size() == 1) continue;
        w = t;
        w += '#';
        w += s;
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        w2 += t;
        w2 += '#';
        w2 += s;
        reverse(s.begin(),s.end());
        int u = w.size(),v= u-n-1;
        rep(i,1,u){
            while (k && w[i] != w[k]) k = f[k-1];
            k += (w[i] == w[k]);
            f[i] = k;
        }
        k = 0;
        rep(i,1,u){
            while (k && w2[i] != w2[k]) k = f2[k-1];
            k += (w2[i] == w2[k]);
            f2[i] = k;
        }
        pre[v+1] = f2[v+1];
        rep(i,v+2,u) pre[i] = max(pre[i-1],f2[i]);
        rep(i,v+1,u-1){
            int x = i-v;
            if (pre[v+n-x] >= v-f[i]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}