#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=(1<<19);
const ll mod=1000000007;
int a[N],b[N];
int c[N];
int p[N];
bool used[N];
bool ch[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) p[a[i]]=b[i];
    for (int i=1;i<=n;i++) if (a[i]==b[i]) c[i]=a[i];
    for (int i=1;i<=n;i++) used[i]=ch[i]=false;
    for (int i=1;i<=n;i++) ch[a[i]]=(c[i]>0);
    int res=1;
    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        int x=i;
        bool was=false;
        while (!used[x]){
            if (ch[x]) was=true;
            used[x]=true;
            x=p[x];
        }
        if (!was) res=(res*2)%mod;
    }
    cout<<res<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
3 3
30 10 40
20 50 60
60 60 50

1001110110

1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/