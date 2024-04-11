//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000010;
bool used[N];
int a[N],b[N],c[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) used[i]=false;
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i],used[b[i]]=true;
    int root=1;
    while (used[root]) root++;
    for (int i=1;i<=n;i++){
        if (i==root) continue;
        cout<<root<<" "<<i<<endl;
    }
}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
1 3
0.0 0.1 0.5 0.2
**/