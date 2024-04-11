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
const long long int N=2e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 131072;
ll a[N],b[N],d[N],n,c,e[N];
bool check(int m){
    rep(i,0,n){
        if (m < d[i]) break;
        if ((m-d[i])*a[i]+e[i] >= c) return 1;
    }
    return 0;
}
int bs(){
    int l = 0,r = c+1,m;
    while(r-l > 1){
        m = (l+r)/2;
        if (check(m)) r = m;
        else l = m;
    }
    return r;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> c;
        rep(i,0,n) cin >> a[i];
        rep(i,0,n-1) cin >> b[i];
        d[1] = (b[0]+a[0]-1)/a[0]+1;
        e[1] = (d[1]-1)*a[0]-b[0];
        rep(i,2,n){
            if (e[i-1] > b[i-1]){
                d[i] = d[i-1]+1;
                e[i] = e[i-1]-b[i-1];
                continue;
            }
            d[i] = (b[i-1]-e[i-1]+a[i-1]-1)/a[i-1];
            e[i] = d[i]*a[i-1]-b[i-1]+e[i-1];
            d[i] += d[i-1]+1;
        }
        cout << bs() << endl;
    }
}