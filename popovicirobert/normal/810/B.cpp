#include <bits/stdc++.h>
#define MAXN 100000
int prod[MAXN+1],cli[MAXN+1];
int profit[MAXN+1];
inline int calc(int a,int b){
   return std::min(a,b);
}
bool cmp(int a,int b){
    return calc(2*prod[a],cli[a])-calc(prod[a],cli[a])>calc(2*prod[b],cli[b])-calc(prod[b],cli[b]);
}
bool viz[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n,f;
    //fi=fopen("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&f);
    for(i=1;i<=n;i++){
        fscanf(fi,"%d%d" ,&prod[i],&cli[i]);
        profit[i]=i;
    }
    std::sort(profit+1,profit+n+1,cmp);
    long long ans=0;
    for(i=1;i<=f;i++){
        viz[profit[i]]=1;
        ans+=calc(2*prod[profit[i]],cli[profit[i]]);
    }
    for(i=1;i<=n;i++)
        if(viz[i]==0)
          ans+=calc(prod[i],cli[i]);
    fprintf(fout,"%I64d" ,ans);
    //fclose(fi);
    //fclose(fout);
    return 0;
}