#include <bits/stdc++.h>
char v[4000];
char s[4000];
int main(){
   FILE*fi,*fout;
   int i,n,p1,p2;
   char a;
 //  fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   fgetc(fi);
   for(i=1;i<=n;i++)
     v[i]=fgetc(fi);
   p1=1;
   p2=n;
   for(i=n;i>=1;i--){
      if((n-i+1)%2==1){
        s[p2]=v[i];
        p2--;
      }
      else{
        s[p1]=v[i];
        p1++;
      }
   }
   for(i=1;i<=n;i++)
     fprintf(fout,"%c" ,s[i]);
  // fclose(fi);
 //  fclose(fout);
   return 0;
}