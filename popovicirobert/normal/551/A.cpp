#include <bits/stdc++.h>
#define MAXN 2000
#define val first
#define poz second
std::pair <int,int> v[MAXN+1];
int sol[MAXN+1];
int main(){
   FILE*fi,*fout;
   int i,n,val;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   scanf("%d " ,&n);
   for(i=1;i<=n;i++){
      scanf("%d" ,&v[i].val);
      v[i].val=-v[i].val;
      v[i].poz=i;
   }
   std::sort(v+1,v+n+1);
   val=0;
   for(i=1;i<=n;i++){
      if(v[i].val!=v[i-1].val)
        val=i;
      sol[v[i].poz]=val;
   }
   for(i=1;i<=n;i++)
      printf("%d " ,sol[i]);
  // fclose(fi);
  // fclose(fout);
   return 0;
}