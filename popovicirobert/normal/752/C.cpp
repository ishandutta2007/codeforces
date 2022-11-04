#include <cstdio>
char v[300000];
int vf[4];
int main(){
   FILE*fi,*fout;
   int n,i,ans,j;
   char a;
  // fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   a=fgetc(fi);
   for(i=1;i<=n;i++)
     v[i]=fgetc(fi);
   ans=1;
   for(i=1;i<=n;i++){
      if(v[i]=='U'){
         if(vf[2]>0){
           ans++;
           for(j=0;j<4;j++)
             vf[j]=0;
           vf[0]=1;
         }
         else
            vf[0]++;
      }
      if(v[i]=='R'){
         if(vf[3]>0){
           ans++;
           for(j=0;j<4;j++)
             vf[j]=0;
           vf[1]=1;
        }
        else
           vf[1]++;
      }
      if(v[i]=='D'){
         if(vf[0]>0){
           ans++;
           for(j=0;j<4;j++)
             vf[j]=0;
           vf[2]=1;
         }
         else
           vf[2]++;
      }
      if(v[i]=='L'){
         if(vf[1]>0){
           ans++;
           for(j=0;j<4;j++)
             vf[j]=0;
           vf[3]=1;
         }
         else
           vf[3]++;
      }
   }
   fprintf(fout,"%d" ,ans);
   //fclose(fi);
  // fclose(fout);
   return 0;
}