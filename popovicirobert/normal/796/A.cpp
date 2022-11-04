#include <bits/stdc++.h>
int v[1000];
int main(){
    FILE*fi,*fout;
    int i,n,m,k,ans;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d" ,&n,&m,&k);
    for(i=1;i<=n;i++)
      fscanf(fi,"%d" ,&v[i]);
    int p=m;
    while(p<=n&&(v[p]==0||v[p]>k))
         p++;
    ans=10*n;
    if(p<=n)
         ans=10*(p-m);
    p=m;
    while(p>0&&(v[p]==0||v[p]>k))
         p--;
    if(p>0)
          ans=std::min(ans,10*(m-p));
    fprintf(fout,"%d" ,ans);
    //fclose(fi);
    //fclose(fout);
    return 0;
}