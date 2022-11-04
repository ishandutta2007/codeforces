#include <cstdio>
#include <algorithm>
#define MAXM 200000
#define INF 1000000000000000000LL
struct A1{
   int t;
   int mana;
};
A1 A[MAXM+1];
bool cmp(A1 a,A1 b){
  return a.mana<b.mana;
}
struct B2{
   int val;
   int mana;
};
B2 B[MAXM+1];
long long min[MAXM+1];
inline long long getmin(long long a,long long b){
   if(a<b) return a;
   return b;
}
int main(){
    FILE*fi,*fout;
    long long ans,x,s;
    int i,n,m,k,rez,pas;
    //fi=fopen("preasimplu.in" ,"r");
   // fout=fopen("preasimplu.out" ,"w");
   fi=stdin;
   fout=stdout;
    fscanf(fi,"%d%d%d" ,&n,&m,&k);
    fscanf(fi,"%I64d%I64d" ,&x,&s);
    ans=x*n;
    for(i=1;i<=m;i++)
       fscanf(fi,"%d" ,&A[i].t);
    for(i=1;i<=m;i++)
       fscanf(fi,"%d" ,&A[i].mana);
    for(i=1;i<=k;i++)
       fscanf(fi,"%d" ,&B[i].val);
    for(i=1;i<=k;i++)
       fscanf(fi,"%d" ,&B[i].mana);
    std::sort(A+1,A+m+1,cmp);
    min[0]=INF;
    for(i=1;i<=m;i++)
       min[i]=getmin(min[i-1],A[i].t);
    for(i=1;i<=k;i++)
    if(B[i].mana<=s){
       rez=0;
       for(pas=1<<18;pas;pas>>=1)
         if(rez+pas<=m&&A[rez+pas].mana<=s-B[i].mana)
           rez+=pas;
       if(B[i].val>=n)
         ans=0;
       else
         ans=getmin(ans,1LL*(n-B[i].val)*getmin(min[rez],x));
    }
    for(i=1;i<=m;i++)
      if(A[i].mana<=s)
        ans=getmin(ans,1LL*A[i].t*n);
    fprintf(fout,"%I64d" ,ans);
   // fclose(fi);
   // fclose(fout);
    return 0;
}