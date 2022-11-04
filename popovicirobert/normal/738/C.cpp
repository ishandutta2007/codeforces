#include <cstdio>
#include <algorithm>
#define MAXN 200000
#define INF 2000000000
struct Car{
   int c;
   int v;
   bool operator <(const Car &x) const{
      if(v==x.v)
         return c<x.c;
      return v<x.v;
   }
};
Car C[MAXN+1];
int g[MAXN+1];
inline char cauta(int poz,int k,int t){
    char flag=1;
    int i;
    long long x;
    long long t1=0;
    for(i=1;i<=k&&flag==1;i++){
        if(g[i]-g[i-1]>C[poz].v)
            flag=0;
        else{
            if(C[poz].v>=2*(g[i]-g[i-1]))
               t1+=g[i]-g[i-1];
            else{
               x=C[poz].v-(g[i]-g[i-1]);
               t1=t1+2*(g[i]-g[i-1])-x;
            }
        }
    }
    if(t1>t)
        flag=0;
    return flag;
}
int main(){
   FILE*fi,*fout;
   int i,n,k,s,t,rez,pas,min;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d%d" ,&n,&k,&s,&t);
   for(i=1;i<=n;i++)
      fscanf(fi,"%d%d" ,&C[i].c,&C[i].v);
   std::sort(C+1,C+n+1);
   for(i=1;i<=k;i++)
      fscanf(fi,"%d" ,&g[i]);
   std::sort(g+1,g+k+1);
   k++;
   g[k]=s;
   rez=0;
   for(pas=1<<18;pas;pas>>=1)
     if(rez+pas<=n&&cauta(rez+pas,k,t)==0)
       rez+=pas;
   if(rez==n)
      fprintf(fout,"-1");
   else{
      min=INF;
      for(i=rez+1;i<=n;i++)
          if(min>C[i].c)
            min=C[i].c;
      fprintf(fout,"%d" ,min);
   }
  // fclose(fi);
  // fclose(fout);
   return 0;
}