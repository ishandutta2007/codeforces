//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> line;
#define endl '\n'
const int N = 1500010;
const int K=500;
const ll mod=998244353;
const ll inf=1e18;
ll a[N];
void solve(){
    ll n,k,b,s;cin>>n>>k>>b>>s;
    s-=b*k;
    if (s<0){
        cout<<-1<<endl;
        return;
    }
    a[1]=b*k;
    for (int i=2;i<=n;i++) a[i]=0;
    for (int i=1;i<=n;i++){
        ll cur=min(s,k-1);
        s-=cur;
        a[i]+=cur;
    }
    if (s>0){
        cout<<-1<<endl;
        return;
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;


}
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 86

**/