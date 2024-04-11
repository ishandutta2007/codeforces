#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 5005

LL p[2],t[2],n,m,f[N],w[2][N],c[2][N];

void cmin(LL &x,LL y){x=min(x,y);}

int main(){
    cin>>p[0]>>t[0]>>p[1]>>t[1];
    cin>>n>>m;
    for (LL i:{0,1}){
        w[i][0]=p[i]-m;
        c[i][0]=t[i];
        for (LL j=1;j<=n;++j){
            LL T=j*t[i];
            if (T<t[i^1]) continue;
            LL num=T/t[i^1];
            w[i][j]=j*p[i]+num*p[i^1];
            w[i][j]-=m*(j+num-1);
            c[i][j]=T;
        }
    }
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for (LL i=0;i<=n;++i){
        for (LL j:{0,1}){
            for (LL k=0;k<=n;++k){
                if (!w[j][k]) continue;
                cmin(f[min(i+w[j][k],n)],f[i]+c[j][k]);
            }
        }
    }
    cout<<f[n]<<'\n';
}