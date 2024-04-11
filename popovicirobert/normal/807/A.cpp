#include <bits/stdc++.h>
#define MAXN 1000
int a[MAXN+1],b[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n;
    //fi=fopen("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    b[0]=(1<<30);
    for(i=1;i<=n;i++){
        fscanf(fi,"%d%d" ,&a[i],&b[i]);
        if(a[i]!=b[i]){
          fprintf(fout,"rated");
          return 0;
        }
    }
    for(i=1;i<=n;i++){
        if(b[i-1]<b[i]){
          fprintf(fout,"unrated");
          return 0;
        }
    }
    fprintf(fout,"maybe");
    //fclose(fi);
    //fclose(fout);
    return 0;
}