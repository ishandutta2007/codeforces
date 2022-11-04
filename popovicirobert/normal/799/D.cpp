#include <bits/stdc++.h>
#define MAXN 100000
int v[MAXN+1];
bool cmp(int a,int b){
   return a>b;
}
long long h,w;
int n;
inline int solve(long long a,long long b){
   int ans=MAXN+1;
   for(int conf=0;conf<(1<<20);conf++){
       int cnt=0,last=-1;
       long long prod=h;
       for(int i=0;i<n&&i<20;i++)
         if(conf&(1<<i)){
            cnt++;
            last=i;
            if(prod<a)
              prod*=v[i];
         }
       if(prod<a)
         cnt=MAXN+1;
       prod=w;
       for(int i=0;i<n&&prod<b;i++)
          if((i<=last&&(conf&(1<<i))==0)||i>last){
             prod*=v[i];
             cnt++;
          }
       if(prod<b)
         cnt=MAXN+1;
       ans=std::min(ans,cnt);
    }
    return ans;
}
int main(){
    FILE*fi,*fout;
    int i,ans;
    long long a,b;
    //fi=fopen("B.in" ,"r");
    //fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%I64d %I64d %I64d %I64d %d " ,&a,&b,&h,&w,&n);
    for(i=0;i<n;i++)
      fscanf(fi,"%d " ,&v[i]);
    std::sort(v,v+n,cmp);
    ans=std::min(solve(a,b),solve(b,a));
    std::swap(h,w);
    ans=std::min(ans,std::min(solve(a,b),solve(b,a)));
    if(ans>MAXN)
      ans=-1;
    fprintf(fout,"%d" ,ans);
    //fclose(fi);
    //fclose(fout);
    return 0;
}