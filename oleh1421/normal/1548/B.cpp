//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000001;
const ll mod=1000000007;
const int N=1000010;
ll a[N];
ll b[N];
ll t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=b[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=__gcd(t[v+v],t[v+v+1]);
}
ll get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return __gcd(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==1){
        cout<<1<<endl;
        return;
    }
    for (int i=1;i<n;i++) b[i]=abs(a[i+1]-a[i]);
    build(1,1,n-1);
    int res=1;
    int j=1;
    for (int i=1;i<n;i++){
        while (j<=i && get(1,1,n-1,j,i)==1) j++;
        res=max(res,i-j+2);
    }
    cout<<res<<endl;

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}