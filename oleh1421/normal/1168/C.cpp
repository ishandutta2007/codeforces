#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int go[300003][31];
int last[31];
int a[300003];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,tt;cin>>n>>tt;
    for (int i=1;i<=n;i++) cin>>a[i];
    int L=30;
    for (int i=0;i<=L;i++) go[n+1][i]=last[i]=n+1;
    for (int i=n;i>=1;i--){
        for (int j=0;j<=L;j++){
            go[i][j]=n+1;
            if (a[i]&(1<<j)) go[i][j]=last[j];
            for (int k=0;k<=L;k++){
                if (a[i]&(1<<k)){
                    go[i][j]=min(go[i][j],go[last[k]][j]);
                }
            }
        }
        for (int j=0;j<=L;j++){
            if (a[i]&(1<<j)) last[j]=i;
        }
    }
    while (tt--){
        int x,y;cin>>x>>y;
        bool ok=false;
        for (int i=0;i<=L;i++){
            if ((a[y]&(1<<i)) && go[x][i]<=y) ok=true;
        }
        if (ok) cout<<"Shi\n";
        else cout<<"Fou\n";
    }
    return 0;
}