//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
int r[500001];
int c[500001];
int a[1010][1010];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>r[i];
    for (int i=1;i<=m;i++) cin>>c[i];
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=-1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=r[i];j++) a[i][j]=1;
        a[i][r[i]+1]=0;
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=c[i];j++){
            if (a[j][i]==0){
                cout<<0;
                return 0;
            }
            a[j][i]=1;
        }
        if (a[c[i]+1][i]==1){
            cout<<0;
            return 0;
        }
        a[c[i]+1][i]=0;
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cnt+=(a[i][j]==-1);
        }
    }
    ll res=1ll;
    for (int i=1;i<=cnt;i++){
        res*=2ll;
        res%=1000000007ll;
    }
    cout<<res;
    return 0;
}
/*
8
0
2 0
0 4 0 1
0 0 0 0 0 5 0 0

*/