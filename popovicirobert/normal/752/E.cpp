#include <cstdio>
#include <cstring>
#include <algorithm>
int v[1000001];
int dp[10000001];
long long cnt=0;
int k;
void bkt(int val,int rez){
    if(val>=2*rez){
      if(dp[val/2]==0)
        bkt(val/2,rez);
      else
        cnt+=dp[val/2];
      if(cnt>=k)
        return;
      if(dp[val/2+val%2]==0)
        bkt(val/2+val%2,rez);
      else
         cnt+=dp[val/2+val%2];
      dp[val]=dp[val/2]+dp[val/2+val%2];
    }
    else{
      cnt++;
      dp[val]=1;
    }
    if(cnt>=k)
      return;
}
inline bool cauta(int rez,int n){
   int i;
   long long con=0;
   memset(dp,0,sizeof(dp));
   for(i=n;i>=1&&v[i]>=rez&&con<=k;i--){
       cnt=0;
       bkt(v[i],rez);
       con+=cnt;
   }
   return con>=k;
}
int main(){
   FILE*fi,*fout;
   int i,n,rez,pas;
  // fi=fopen("E.in" ,"r");
   //fout=fopen("E.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d" ,&n,&k);
   for(i=1;i<=n;i++)
      fscanf(fi,"%d" ,&v[i]);
   std::sort(v+1,v+n+1);
   rez=0;
   for(pas=1<<23;pas;pas>>=1)
     if(cauta(rez+pas,n)==1)
        rez+=pas;
   if(rez==0)
     rez=-1;
   fprintf(fout,"%d" ,rez);
  // fclose(fi);
  // fclose(fout);
   return 0;
}