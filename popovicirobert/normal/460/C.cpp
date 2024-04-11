#include <bits/stdc++.h>
#define MAXN 100000
int h[MAXN+1];
int v[MAXN+1];
int n,m,w;
inline bool check(int val){
    int i,x,st;
    memset(v,0,sizeof(v));
    st=0;
    x=m;
    for(i=1;i<=n;i++){
       if(i-w>=0)
        st-=v[i-w];
       while(x>0&&h[i]+v[i]+st<val){
          x--;
          v[i]++;
       }
       if(h[i]+v[i]+st<val)
        return 0;
       st+=v[i];
    }
    return 1;
}
int main(){
   FILE*fi,*fout;
   int i,rez,pas;
   //fi=fopen("C.in" ,"r");
  // fout=fopen("C.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d" ,&n,&m,&w);
   for(i=1;i<=n;i++)
     fscanf(fi,"%d" ,&h[i]);
   rez=0;
   for(pas=1<<30;pas;pas>>=1)
     if(check(rez+pas))
       rez+=pas;
   fprintf(fout,"%d" ,rez);
   fclose(fi);
 ////  fclose(fout);
   return 0;
}