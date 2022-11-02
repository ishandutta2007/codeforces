#include<stdio.h>
#include<string.h>
int dp[12010000];
long long sid[1010000];
int l[1010000];
int zero=0;
inline int& g(int n,int c){
   if(c>l[n])return zero;
   return dp[sid[n]+c];
}
int n,m;
int p;
int a[5010][5010];
inline int add(long long a,int b){
   a+=b;
   if(a>=p)a-=p;
   return a;
}
inline int sub(long long a,int b){
   a-=b;
   if(a<0)a+=p;
   return a;
}
inline int mul(long long a,int b){
   return (a*b)%p;
}
int ms[5010];
int np[100000];
int pr[100000],pc=0;
inline void init(){
   long long i,j;
   for(i=2;i<100000;i++)if(!np[i]){
      pr[pc++]=i;
      for(j=i*i;j<100000;j+=i)np[j]=1;
   }
}
int pfc[1000],pfcc[1000],tot;
inline void fac(int n){
   tot=0;
   int i;
   for(i=0;n>1&&i<pc&&pr[i]*pr[i]<=n;i++){
      if(n%pr[i]==0){
         pfc[tot]=pr[i];
         pfcc[tot]=0;
         while(n%pr[i]==0){
            n/=pr[i];
            pfcc[tot]++;
         }
         tot++;
      }
   }
   if(n>1){
      pfc[tot]=n;
      pfcc[tot]=1;
      tot++;
   }
}
int lb[1000];
inline int inv(long long a,long long b){
   if(a==1)return 1;
   int x=((1-inv(b%a,a)*b)/a)%b;
   if(x<0)x+=b;
   return x;
}
inline int bp(int a,int b){//a^b
   if(b==0)return 1;
   if(b==1)return a%p;
   int r=bp(a,b/2);
   r=mul(r,r);
   if(b%2)r=mul(r,a);
   return r;
}
int main(){
   init();
   int i,j;
   scanf("%d%d%d",&n,&m,&p);
   fac(p);
   int ml=0;
   sid[0]=0;
   for(i=0;i<n;i++){
      scanf("%d",&l[i]);
      sid[i+1]=sid[i]+l[i]+1;
      if(ml<l[i])ml=l[i];
   }
   a[1][1]=1;
   for(i=2;i<=ml;i++){
      a[i][1]=0;
      for(j=2;j<=i;j++){
         a[i][j]=add(mul(a[i-1][j],j-1),mul(a[i-1][j-1],j));
         //printf("a[%d][%d]=%d\n",i,j,a[i][j]);
      }
   }
   ms[0]=1;
   int pl=1;
   for(i=1;i<=ml;i++){
      if(i>=m+1){
         ms[i]=0;
         continue;
      }
      int x=i;
      for(j=0;j<tot;j++){
         while(x%pfc[j]==0){
            x/=pfc[j];
            lb[j]--;
         }
      }
      int y=m-i+1;
      for(j=0;j<tot;j++){
         while(y%pfc[j]==0){
            y/=pfc[j];
            lb[j]++;
         }
      }
      pl=mul(pl,y);
      pl=mul(pl,inv(x,p));
      int c=1;
      for(j=0;j<tot;j++){
         //printf("%d lb[%d]=%d\n",pfc[j], j,lb[j]);
         c=mul(c,bp(pfc[j],lb[j]));
      }
      //printf("pl=%d c=%d\n",pl,c);
      ms[i]=mul(pl,c);
      //printf("ms[%d]=%d\n",i,ms[i]);
   }
   for(i=1;i<=l[0];i++){
      g(0,i)=mul(a[l[0]][i],ms[i]);
      //printf("%d %d %d\n",0,i,g(0,i));
   }
   for(i=1;i<n;i++){
      int s=0;
      for(j=1;j<=l[i-1];j++)s=add(s,g(i-1,j));
      //printf("i=%d s=%d\n",i,s);
      for(j=1;j<=l[i];j++){
         g(i,j)=sub(mul(mul(s,a[l[i]][j]),ms[j]),mul(g(i-1,j),a[l[i]][j]));
         //printf("%d %d %d\n",i,j,g(i,j));
      }
   }
   int s=0;
   for(i=1;i<=l[n-1];i++)s=add(s,g(n-1,i));
   printf("%d\n",s);
}