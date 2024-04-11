#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[101];
int t[101][101];
int res[101][101];
int main() {
    int n,m,h;cin>>n>>m>>h;
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cin>>t[i][j];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (t[i][j]) res[i][j]=min(b[i],a[j]);
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}