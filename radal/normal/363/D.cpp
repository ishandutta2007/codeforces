#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e5+30,mod = 1e9+7,inf=1e12;
ll b[N],p[N];
ll n,m,a;
bool check(int r){
    int p1 = r-1;
    ll sum=0;
    repr(i,n-1,n-r){
        sum += max(b[i]-b[i],p[p1]-b[i]);
        p1--;
    }
    return sum <= a;
}
ll binar(int l,int r){
    int mid;
    if (check(r)) return r;
    while (r-l > 1){
        mid = (l+r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main(){
    cin >> n >> m >> a;
    rep(i,0,n) cin >> b[i];
    rep(i,0,m) cin >> p[i];
    sort(b,b+n);
    sort(p,p+m);
    ll ans = binar(0,min(n,m));
    ll sum=0,s=0,p1=ans-1;
    repr(i,n-1,n-ans){
       // s += max(b[i]-b[i],p[p1]-b[i]);
        sum += p[p1];
        p1--;
    }
    cout << ans << ' ' << max(a-a,sum-a);
    return 0;
}