#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[101][101];
int b[101][101];
int c[101][101];
int d[101][101];
int main()
{
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[i][j];
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>b[i][j];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            c[i][j]=min(a[i][j],b[i][j]);
            d[i][j]=max(a[i][j],b[i][j]);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=2;j<=m;j++){
            if (c[i][j]<=c[i][j-1] || d[i][j]<=d[i][j-1]){
                cout<<"Impossible";
                return 0;
            }
        }
    }
    for (int j=1;j<=m;j++){
        for (int i=2;i<=n;i++){
            if (c[i][j]<=c[i-1][j] || d[i][j]<=d[i-1][j]){
                cout<<"Impossible";
                return 0;
            }
        }
    }
    cout<<"Possible";
    return 0;
}