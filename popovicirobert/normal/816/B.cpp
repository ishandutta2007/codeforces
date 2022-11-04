#include <bits/stdc++.h>
#define MAXN 200000
int sp[MAXN + 10];
int sp1[MAXN + 10];
int main(){
    FILE*fi,*fout;
    int i,n,k,q,l,r;
   // fi=fopen("B.in" ,"r");
   // fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d" ,&n,&k,&q);
    for(i=1;i<=n;i++){
      fscanf(fi,"%d%d" ,&l,&r);
      sp[l]++;
      sp[r+1]--;
    }
    for(i=1;i<=MAXN;i++)
      sp[i]+=sp[i-1];
    for(i=1;i<=MAXN;i++){
       if(sp[i]>=k)
         sp1[i]=1;
       sp1[i]+=sp1[i-1];
    }
    while(q>0){
       q--;
       fscanf(fi,"%d%d" ,&l,&r);
       fprintf(fout,"%d\n" ,sp1[r]-sp1[l-1]);
    }
   // fclose(fi);
   // fclose(fout);
    return 0;
}