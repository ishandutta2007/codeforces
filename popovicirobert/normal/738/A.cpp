#include <cstdio>
char v[200];
int main(){
   FILE*fi,*fout;
   int i,n,poz;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   fgetc(fi);
   for(i=1;i<=n;i++)
      v[i]=fgetc(fi);
   i=1;
   while(i<=n){
      if(v[i]=='o'&&v[i+1]=='g'&&v[i+2]=='o'){
        poz=i+3;
        while(poz<n&&v[poz]=='g'&&v[poz+1]=='o')
          poz+=2;
        fprintf(fout,"***");
        i=poz;
      }
      else{
        fprintf(fout,"%c" ,v[i]);
        i++;
      }
   }
  // fclose(fi);
  // fclose(fout);
   return 0;
}