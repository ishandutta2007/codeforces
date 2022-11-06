#include <bits/stdc++.h>
char v[51];
char mat[51][51];
int main(){
   FILE*fi,*fout;
   int i,n,x,l,j,m;
   char aux;
 //  fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   scanf("%s" ,&v);
   x=strlen(v);
   m=0;
   for(i=0;i<x;i++){
      for(j=0;j<m;j++){
         l=0;
         while(l<x&&mat[j][l]==v[l])
            l++;
         if(l==x)
           j=m+1;
      }
      if(j==m){
         for(j=0;j<x;j++)
           mat[m][j]=v[j];
         m++;
      }
      aux=v[0];
      for(j=1;j<x;j++)
        v[j-1]=v[j];
      v[x-1]=aux;
   }
   fprintf(fout,"%d" ,m);
  // fclose(fi);
 //  fclose(fout);
   return 0;
}