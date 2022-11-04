#include <bits/stdc++.h>
#define SIZE 100001
char A[SIZE+1];
char B[SIZE+1];
int posleft[SIZE+1];
int posright[SIZE+1];
int n,m;
int l,r;
inline bool check(int len){
   int i;
   bool flag=0;
   for(i=1;i+len<=m+1;i++)
      if(posleft[i-1]<posright[i+len]){
          l=i;
          r=i+len-1;
          flag=1;
      }
   return flag;
}
int main(){
   FILE*fi,*fout;
   int i,pos,rez,pas;
  // fi=fopen("C.in" ,"r");
 //  fout=fopen("C.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%s" ,&A);
   fscanf(fi,"%s" ,&B);
   n=strlen(A);
   for(i=n;i>=1;i--)
     A[i]=A[i-1];
   m=strlen(B);
   for(i=m;i>=1;i--)
     B[i]=B[i-1];
   pos=1;
   for(i=1;i<=m;i++){
      while(pos<=n&&A[pos]!=B[i])
        pos++;
      posleft[i]=pos;
      pos++;
   }
   pos=n;
   for(i=m;i>=1;i--){
      while(pos>=1&&A[pos]!=B[i])
        pos--;
      posright[i]=pos;
      pos--;
   }
   posright[m+1]=n+1;
   rez=-1;
   for(pas=1<<17;pas;pas>>=1)
     if(rez+pas<m&&check(rez+pas)==0)
       rez+=pas;
   rez++;
   check(rez);
   if(rez==m)
     fprintf(fout,"-");
   else
     for(i=1;i<=m;i++)
       if(!(l<=i&&i<=r))
         fprintf(fout,"%c" ,B[i]);
   //fclose(fi);
  // fclose(fout);
   return 0;
}