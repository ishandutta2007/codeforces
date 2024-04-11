#include <cstdio>
int a[200001][18],b[200001][18];
int lg[200001];
inline int getmax(int a,int b){
    if(a<b)
         return b;
    return a;
}
inline int getmin(int a,int b){
    if(a<b)
         return a;
    return b;
}
int main(){
    int i,j,n,rez,pas,st;
    long long con;
    scanf("%d" ,&n);
    for(i=1;i<=n;i++)
      scanf("%d" ,&a[i][0]);
    for(i=1;i<=n;i++)
      scanf("%d" ,&b[i][0]);
    lg[1]=0;
    for(i=2;i<=n;i++)
      if((1<<(lg[i-1]+1))==i)
        lg[i]=lg[i-1]+1;
      else
        lg[i]=lg[i-1];
    for(i=1;i<=lg[n];i++)
      for(j=1;j+(1<<i)<=n+1;j++){
         a[j][i]=getmax(a[j][i-1],a[j+(1<<(i-1))][i-1]);
         b[j][i]=getmin(b[j][i-1],b[j+(1<<(i-1))][i-1]);
      }
    con=0;
    for(i=1;i<=n;i++){
        rez=i-1;
        for(pas=1<<17;pas;pas>>=1)
          if(rez+pas<=n&&getmax(a[i][lg[rez+pas-i+1]],a[rez+pas-(1<<lg[rez+pas-i+1])+1][lg[rez+pas-i+1]])<getmin(b[i][lg[rez+pas-i+1]],b[rez+pas-(1<<lg[rez+pas-i+1])+1][lg[rez+pas-i+1]]))
            rez+=pas;
        st=rez+1;
        rez=i;
        for(pas=1<<17;pas;pas>>=1)
          if(rez+pas<=n&&getmax(a[i][lg[rez+pas-i+1]],a[rez+pas-(1<<lg[rez+pas-i+1])+1][lg[rez+pas-i+1]])<=getmin(b[i][lg[rez+pas-i+1]],b[rez+pas-(1<<lg[rez+pas-i+1])+1][lg[rez+pas-i+1]]))
            rez+=pas;
        if(getmax(a[i][lg[rez-i+1]],a[rez-(1<<lg[rez-i+1])+1][lg[rez-i+1]])==getmin(b[i][lg[rez-i+1]],b[rez-(1<<lg[rez-i+1])+1][lg[rez-i+1]]))
          con+=rez-st+1;
        //printf("%d %d %d\n" ,rez,st,getmax(a[i][lg[rez-i+1]],a[rez-(1<<lg[rez-i+1])+1][lg[rez-i+1]]));
    }
    printf("%I64d" ,con);
    return 0;
}