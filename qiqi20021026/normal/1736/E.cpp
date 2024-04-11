#include<bits/stdc++.h>

using namespace std;

#define N 505

int n,a[N],ans,f[N][N][N];

void cmax(int &x,int y){x=max(x,y);}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    memset(f,0xcf,sizeof f);
    f[0][0][0]=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=i;++j){
            for (int k=0;k<=n;++k){
                cmax(f[i][j][k],f[i-1][j-1][k]+a[k]);
            }
        }
        for (int j=0;j<=i;++j){
            for (int k=1;k<=n;++k){
                cmax(f[i-1][j][k],f[i-1][j][k-1]);
            }
        }
        for (int j=0;j<=i;++j){
            for (int k=i;k<=n&&k-i<=j;++k){
                cmax(f[i][j][k],f[i-1][j-(k-i)][k-1]+a[k]);
            }
        }
    }
    int ans=0;
    for (int i=0;i<=n;++i){
        for (int j=0;j<=n;++j) cmax(ans,f[n][i][j]);
    }
    cout<<ans<<'\n';
}