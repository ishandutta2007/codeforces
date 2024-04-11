#include <bits/stdc++.h>
#define MAXN 200000
int vf[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n,cnt,ans,x;
   // fi=fopen("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    cnt=0;
    ans=0;
    for(i=1;i<=2*n;i++){
        fscanf(fi,"%d" ,&x);
        if(vf[x]==1){
            cnt--;
            vf[x]--;
        }
        else{
            vf[x]++;
            cnt++;
        }
        ans=std::max(cnt,ans);
    }
    fprintf(fout,"%d" ,ans);
   // fclose(fi);
   // fclose(fout);
    return 0;
}