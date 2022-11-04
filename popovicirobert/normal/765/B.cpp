#include <bits/stdc++.h>
bool f[256];
int main(){
   FILE*fi,*fout;
   int cnt;
   bool flag;
   char ch;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   ch=fgetc(fi);
   flag=1;
   cnt=0;
   while(isalpha(ch)&&flag){
     if(ch>cnt+'a')
        flag=0;
     if(f[ch]==0){
        f[ch]=1;
        cnt++;
     }
     ch=fgetc(fi);
   }
   if(flag==1)
     fprintf(fout,"YES");
   else
     fprintf(fout,"NO");
  // fclose(fi);
  // fclose(fout);
   return 0;
}