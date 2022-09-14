#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll inf=1000000000000000001;
int cnt[30];
int dsu[N];
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
int TOT;
void unite(int a,int b){
    a=get(a);
    b=get(b);
    if (a!=b){
        TOT--;
        dsu[a]=b;
    }
}
int a[N],b[N],c[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
    int ans=0;
    for (int i=29;i>=0;i--){
        int mask=ans^((1<<i)-1);
        TOT=n;
        for (int j=1;j<=n;j++) dsu[j]=j;
        for (int j=1;j<=m;j++){
            if ((c[j]&mask)==c[j]){
                unite(a[j],b[j]);
            }
        }
        if (TOT>1) ans|=(1<<i);
    }
    cout<<ans<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;

}

/**

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/