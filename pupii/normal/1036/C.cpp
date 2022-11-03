// It is made by XZZ
#include<bits/stdc++.h>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0;rg char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
int f[20][5][2],w[20];
il int dp(int x){
    memset(f,0,sizeof f);
    for(int i=19;i;--i)w[i]=x%10,x/=10;
    f[0][0][1]=1;
    for(int i=0;i<19;++i)
        for(int j=0;j<4;++j){
            f[i+1][j][0]+=f[i][j][0];
            f[i+1][j+1][0]+=f[i][j][0]*9;
            if(w[i+1]==0)f[i+1][j][1]+=f[i][j][1];
            else{
                f[i+1][j][0]+=f[i][j][1];
                f[i+1][j+1][0]+=f[i][j][1]*(w[i+1]-1);
                f[i+1][j+1][1]+=f[i][j][1];
            }
        }
    int ret=0;
    for(int i=0;i<4;++i)ret+=f[19][i][0]+f[19][i][1];
    return ret;
}
main(){
    int q=gi();
    while(q--){
        int l=gi(),r=gi();
        printf("%lld\n",dp(r)-dp(l-1));
    }
    return 0;
}