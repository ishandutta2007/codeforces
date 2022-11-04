#include <bits/stdc++.h>

int main(){
    FILE*fi,*fout;
    int i,n,t,k,d,ans,cnt;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d%d" ,&n,&t,&k,&d);
    ans=((n/k)+((n%k)>0))*t;
    cnt=0;
    for(i=1;cnt<n;i++){
       if(i%t==0)
         cnt+=k;
       if(i>d&&(i-d)%t==0)
         cnt+=k;
    }
    i=i-1;
    if(ans<=i)
      fprintf(fout,"NO");
    else
      fprintf(fout,"YES");
    //fclose(fi);
    //fclose(fout);
    return 0;
}