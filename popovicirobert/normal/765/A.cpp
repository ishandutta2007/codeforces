#include <bits/stdc++.h>
inline int getstr(FILE *fi){
   int nr=0;
   char ch;
   ch=fgetc(fi);
   nr=nr*27+ch-'A'+1;
   ch=fgetc(fi);
   nr=nr*27+ch-'A'+1;
   ch=fgetc(fi);
   nr=nr*27+ch-'A'+1;
   return nr;
}
int main(){
   FILE*fi,*fout;
   int i,n,cnt,val,val1,val2;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d " ,&n);
   val=getstr(fi);
   cnt=0;
   for(i=1;i<=n;i++){
      fgetc(fi);
      val1=getstr(fi);
      fgetc(fi);
      fgetc(fi);
      val2=getstr(fi);
      if(val1==val)
        cnt++;
      if(val2==val)
        cnt--;
   }
   if(cnt==0)
     fprintf(fout,"home");
   else
     fprintf(fout,"contest");
  // fclose(fi);
  // fclose(fout);
   return 0;
}