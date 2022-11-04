#include <bits/stdc++.h>
#define MAXN 1000000
bool f[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n,m,k,x,flag,a,b;
    //fi=fopen("B.in" ,"r");
    //fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d" ,&n,&m,&k);
    for(i=1;i<=m;i++){
        fscanf(fi,"%d" ,&x);
        f[x]=1;
    }
    flag=1;
    if(f[1]==1)
         flag=0;
    x=1;
    while(k>0&&flag){
        k--;
        fscanf(fi,"%d%d" ,&a,&b);
        if(x==a){
            if(f[b]==1)
              flag=0;
            x=b;
        }
        else if(x==b){
            if(f[a]==1)
               flag=0;
            x=a;
        }
    }
    fprintf(fout,"%d" ,x);
    //fclose(fi);
    //fclose(fout);
    return 0;
}