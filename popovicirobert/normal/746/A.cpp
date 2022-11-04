#include <bits/stdc++.h>
inline int getmin(int a,int b){
   if(a<b) return a;
   return b;
}
int main(){
   FILE*fi,*fout;
   int a,b,c;
 //  fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d" ,&a,&b,&c) ;
   fprintf(fout,"%d" ,getmin(a,getmin(b/2,c/4))*7);
  // fclose(fi);
 //  fclose(fout);
   return 0;
}