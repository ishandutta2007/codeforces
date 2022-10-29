#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int mod=998244353;
const int N=1<<15;
int Jie[N],inv[N],jie[N];
inline int mul(const int &a,const int &b){
    return 1ll*a*b%mod; 
} 
inline void add(int &a,const int &b){
    a+=b;
    if(a>=mod)a-=mod;
    return ;
}
inline int C(int m,int n){
    return mul(jie[m],mul(inv[n],inv[m-n]));
}
inline int CC(int m,int n){
    return mul(Jie[m],inv[n]);
}
int main(){
//    freopen("test.in","w",stdout);
    int n=1000000000,k=32767;
    scanf("%d%d",&n,&k);
    Jie[0]=n;
    jie[0]=1,inv[0]=inv[1]=1;
    rep(i,2,k+1)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
    rep(i,1,k+1){
        Jie[i]=n-i;
        jie[i]=mul(jie[i-1],i);
        inv[i]=mul(inv[i],inv[i-1]);
    }
 //   auto t=clock();
    rep(i,1,min(k,n)+1){
        int ans=0;
        rep(j,0,i+1){
            if(n-j<i)break;
            ans=(ans+1ll*C(i,j)*CC(j,i))%mod; 
        //    cout<<i<<' '<<j<<' '<<C(i,j)<<' '<<CC(j,i)<<"check\n";
        }
        rep(j,0,k+1)Jie[j]=1ll*Jie[j]*(n-i-j)%mod;
        printf("%d ",ans);
    }
 //   cout<<(clock()-t)/CLOCKS_PER_SEC<<'\n'; 
    rep(i,min(k,n)+1,k+1){
        printf("0 ");
    }
}