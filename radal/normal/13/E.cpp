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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e9,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int a[N];
pll nxt[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q,s;
    cin >> n >> q;
    s = sqrt(n)+1;
    rep(i,1,n+1)
        cin >> a[i];
    repr(i,n,1){
        if (i+a[i] > n){
            nxt[i] = {1,n+1};
            continue;
        }
        if (i/s != (a[i]+i)/s){
            nxt[i] = {1,a[i]+i};
            continue;
        }
        nxt[i].X = nxt[a[i]+i].X+1;
        nxt[i].Y = nxt[a[i]+i].Y;
    }
    rep(i,0,q){
        int c;
        cin >> c;
        if (c){
            int x;
            cin >> x;
            int y=x,ans=0,z; 
            while (nxt[y].Y != n+1){
                ans += nxt[y].X;
                y = nxt[y].Y;
            }
            while (y < n+1){
                ans++;
                z = y;
                y = y+a[y];
            }
            cout << z << ' ' << ans << endl;
            continue;
        }
        int x,y,l;
        cin >> x >> y;       
        l = x-x%s;
        a[x] = y;
        repr(j,x,l){
            if (j+a[j] > n){
                nxt[j] = {1,n+1};
                continue;
            }
            if ((j+a[j])/s != j/s){
                nxt[j] = {1,j+a[j]};
                continue;
            }
            nxt[j].X = 1+nxt[j+a[j]].X;
            nxt[j].Y = nxt[j+a[j]].Y;
        }
    }
    return 0;
}