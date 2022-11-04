#include <bits/stdc++.h>
#define MAXN 100000
bool f[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n,x,poz;
   // fi=fopen("A.in" ,"r");
  //  fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    poz=n;
    for(i=1;i<=n;i++){
      fscanf(fi,"%d" ,&x);
      f[x]=1;
      if(poz==x){
         while(poz>0&&f[poz]==1){
            fprintf(fout,"%d " ,poz);
            poz--;
         }
      }
        fprintf(fout,"\n");
    }
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}