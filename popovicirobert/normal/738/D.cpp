#include <cstdio>
#define MAXN 200010
char v[MAXN+1];
int l[MAXN+1];
int main(){
   FILE*fi,*fout;
   int i,j,n,a,b,k,m,con,ans;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d%d" ,&n,&a,&b,&k);
   fgetc(fi);
   for(i=1;i<=n;i++)
     v[i]=fgetc(fi)-'0';
   v[0]=v[n+1]=1;
   i=0;
   m=0;
   ans=0;
   while(i<=n){
      j=i+1;
      con=0;
      while(j<=n+1&&v[j]==0){
         j++;
         con++;
      }
      ans+=con/b;
      i=j;
   }
   ans=ans-a+1;
   fprintf(fout,"%d\n" ,ans);
   i=0;
   while(ans>0){
      j=i+1;
      con=0;
      while(ans>0&&j<=n+1&&v[j]==0){
          con++;
          if(con==b){
             ans--;
             fprintf(fout,"%d " ,j);
             con=0;
          }
          j++;
      }
      i=j;
   }
   fclose(fi);
   fclose(fout);
   return 0;
}