#include <cstdio>
#include <cctype>
char A[2000];
char B[2000];
int v[200];
bool f[200];
int main(){
   FILE*fi,*fout;
   int n,i,flag,con;
   char a;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   a=fgetc(fi);
   n=0;
   while(isalpha(a)){
     A[++n]=a;
     a=fgetc(fi);
   }
   a=fgetc(fi);
   n=0;
   while(isalpha(a)){
     B[++n]=a;
     a=fgetc(fi);
   }
   flag=1;
   con=0;
   for(i=1;i<=n;i++)
     if(v[A[i]]==0&&v[B[i]]==0){
       v[A[i]]=B[i];
       f[A[i]]=1;
       v[B[i]]=A[i];
       if(A[i]!=B[i])
       con++;
     }
     else
      if(v[B[i]]!=A[i])
        flag=0;
   if(flag==1)
   fprintf(fout,"%d\n" ,con);
   if(flag==1){
      for(i=1;i<=150;i++)
        if(v[i]!=0&&f[i]&&v[i]!=i){
          fprintf(fout,"%c %c\n" ,i,v[i]);
          v[v[i]]=0;
        }
   }
   else
     fprintf(fout,"-1");
  // fclose(fi);
   //fclose(fout);
   return 0;
}