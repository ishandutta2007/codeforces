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
ll mult[N];
int b[N];
ll ANS=0ll;
void upd(int pos,int x){
    ANS-=mult[pos]*b[pos];
    b[pos]=x;
    ANS+=mult[pos]*b[pos];
}

void solve(){
    ll n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++){
        mult[i]=1ll*i*(n-i);
    }
    ANS=n*(n+1)/2;

    for (int i=1;i<n;i++){
        b[i]=0;
        upd(i,(a[i]!=a[i+1]));
    }
    for (int i=1;i<=m;i++){
        int pos,x;cin>>pos>>x;
        a[pos]=x;
        if (pos>1) upd(pos-1,(a[pos-1]!=a[pos]));
        if (pos<n) upd(pos,(a[pos]!=a[pos+1]));
        cout<<ANS<<'\n';
    }




}
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;

    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 86

**/