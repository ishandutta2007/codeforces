#include <bits/stdc++.h>
#define MAXN 100010
int v[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n;
   // fi=fopen("B.in" ,"r");
  //  fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++)
        fscanf(fi,"%d" ,&v[i]);
    std::sort(v+1,v+n+1);
    i=1;
    while(i+2<=n&&v[i]+v[i+1]<=v[i+2])
         i++;
    if(i+2==n+1)
         fprintf(fout,"NO");
    else
          fprintf(fout,"YES");
   // fclose(fi);
   // fclose(fout);
    return 0;
}