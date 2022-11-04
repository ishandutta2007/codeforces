#include <bits/stdc++.h>
int v[10];
int main(){
    FILE*fi,*fout;
    int i,n,x,j,aux;
   // fi=fopen("A.in" ,"r");
  //  fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&x);
    x++;
    n%=6;
    if(n==0)
    n=6;
    for(i=1;i<=3;i++){
       v[1]=1;
       v[2]=2;
       v[3]=3;
       for(j=1;j<=n;j++){
         if(j%2==1){
            aux=v[1];
            v[1]=v[2];
            v[2]=aux;
         }
         else{
            aux=v[3];
            v[3]=v[2];
            v[2]=aux;
         }
       }
       j=1;
       while(v[j]!=i)
          j++;
       if(j==x){
          fprintf(fout,"%d" ,i-1);
          return 0;
       }
    }
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}