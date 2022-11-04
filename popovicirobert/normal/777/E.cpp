#include <bits/stdc++.h>
#define MAXN 200010
struct Data{
   int a;
   int b;
   int h;
   bool operator <(const Data &x) const{
      if(b==x.b)
         return a>x.a;
      return b>x.b;
   }
}v[MAXN+1];
struct Norm{
   int val;
   int poz;
   bool t;
   bool operator <(const Norm &x) const{
      return val<x.val;
   }
};
Norm A[MAXN+1];
long long dp[MAXN+1];
#define zeros(x) (x&(-x))
long long aib[MAXN+1];
inline void update(int poz,long long val,int s){
    for(int i=poz;i<s;i+=zeros(i))
      aib[i]=std::max(aib[i],val);
}
inline long long query(int poz){
    long long ans=0;
    for(int i=poz;i>0;i-=zeros(i))
      ans=std::max(aib[i],ans);
    return ans;
}
int main(){
    FILE*fi,*fout;
    int i,j,n,m,cnt;
    long long ans;
 //   fi=fopen("E.in" ,"r");
 //   fout=fopen("E.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    m=0;
    for(i=1;i<=n;i++){
      fscanf(fi,"%d%d%d" ,&v[i].a,&v[i].b,&v[i].h);
      m++;
      A[m].val=v[i].a;
      A[m].poz=i;
      A[m].t=0;
      m++;
      A[m].val=v[i].b;
      A[m].poz=i;
      A[m].t=1;
    }
    std::sort(A+1,A+m+1);
    A[0].val=-1;
    cnt=0;
    for(i=1;i<=m;i++){
        if(A[i].val!=A[i-1].val)
           cnt++;
       if(A[i].t==0)
            v[A[i].poz].a=cnt;
        else
            v[A[i].poz].b=cnt;
    }
    std::sort(v+1,v+n+1);
    ans=0;
    for(i=1;i<=n;i++){
        dp[i]=query(v[i].b-1)+v[i].h;
        update(v[i].a,dp[i],cnt);
        ans=std::max(ans,dp[i]);
    }
    fprintf(fout,"%I64d" ,ans);
    //printf();
   // fclose(fi);
  //  fclose(fout);
    return 0;
}