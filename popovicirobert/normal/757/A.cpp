#include <bits/stdc++.h>
int vf[1000];
inline int getmin(int a,int b){
   if(a<b) return a;
   return b;
}
int main(){
   FILE*fi,*fout;
   char a;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   a=fgetc(fi);
   while(isalpha(a)){
      vf[a]++;
      a=fgetc(fi);
   }
   fprintf(fout,"%d" ,getmin(vf['B'],getmin(vf['a']/2,getmin(vf['b'],getmin(vf['l'],getmin(vf['r'],getmin(vf['u']/2,vf['s'])))))));
  // fclose(fi);
  // fclose(fout);
   return 0;
}