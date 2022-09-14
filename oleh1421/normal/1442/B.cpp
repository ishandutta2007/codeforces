#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500100;
const ll mod=998244353;
int a[N];
int b[N];
int pos[N];
int p[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
    for (int i=1;i<=n;i++) p[i]=0;
    for (int i=1;i<=k;i++){
        cin>>b[i];
        p[pos[b[i]]]=i;
    }
    p[0]=k+1;
    p[n+1]=k+1;
    ll res=1ll;
    for (int i=1;i<=n;i++){
        if (!p[i]) continue;
        ll cnt=(p[i-1]<p[i])+(p[i]>p[i+1]);
        res*=cnt;
        res%=mod;
    }

    cout<<res<<endl;

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
7 4
1 4 7 3 6 2 5
3 2 4 5
*/