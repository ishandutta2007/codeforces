#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 300000
int x[MAXN+1];
int right[MAXN+2];
int left[MAXN+2];
inline void mod(int &x){
    if(x>=MOD)
          x-=MOD;
}
int main(){
    FILE*fi,*fout;
    int i,n;
    //fi=fopen("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++)
        fscanf(fi,"%d" ,&x[i]);
    std::sort(x+1,x+n+1);
    for(i=n;i>=1;i--){
        right[i]=right[i+1]+x[i];
        mod(right[i]);
    }
    for(i=1;i<=n;i++){
        left[i]=left[i-1]+x[i];
        mod(left[i]);
    }
    int p2=1;
    long long ans=0;
    for(i=1;i<=n-1;i++){
        ans+=1LL*p2*(right[n-i+1]-left[i]+MOD);
        ans%=MOD;
        p2*=2;
        mod(p2);
    }
    fprintf(fout,"%I64d" ,ans);
    //fclose(fi);
    //fclose(fout);
    return 0;
}