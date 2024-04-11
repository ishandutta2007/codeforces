//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
ll a[N];
ll b[N];
int n;
bool ok(int d){
    int L=(d+n)/4;
    ll A=d*100ll+a[n]-a[L];
    ll B=b[n];
    B-=b[max(0,L-d)];
    return (A>=B);
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++) a[i]+=a[i-1];
    for (int i=1;i<=n;i++) b[i]+=b[i-1];
    int L=0,R=3*n;
    while (R-L>1){
        int mid=(L+R)/2;
        if (ok(mid)) R=mid;
        else L=mid;
    }
    if (ok(L)) R=L;
    cout<<R<<endl;

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
/**
1
5
6 9 1 9 6
**/