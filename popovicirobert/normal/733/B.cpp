#include <bits/stdc++.h>
#define MAXN 100000
int l[MAXN+1],r[MAXN+1];
int main(){
    FILE*fi,*fout;
    int n,i,poz,ans,L,R;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    L=R=0;
    for(i=1;i<=n;i++){
       fscanf(fi,"%d%d" ,&l[i],&r[i]);
       L+=l[i];
       R+=r[i];
    }
    poz=0;
    ans=std::abs(L-R);
    for(i=1;i<=n;i++){
       if(ans<std::abs((R-r[i]+l[i])-(L-l[i]+r[i]))){
         ans=std::abs((R-r[i]+l[i])-(L-l[i]+r[i]));
         poz=i;
       }
    }
    fprintf(fout,"%d" ,poz);
    //fclose(fi);
    //fclose(fout);
    return 0;
}