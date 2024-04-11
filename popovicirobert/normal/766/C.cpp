#include <bits/stdc++.h>
#define MAXN 2000
#define MOD 1000000007
char A[MAXN+1];
int dp[MAXN+1];
int len[MAXN+1];
int d[MAXN+1];
int a[30];

int main(){
    FILE*fi,*fout;
    int i,n,cnt,j,let,x;
   // fi=fopen("C.in" ,"r");
  //  fout=fopen("C.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    fscanf(fi,"%s" ,&A);
    for(i=n;i>=1;i--)
        A[i]=A[i-1]-'a';
    for(i=0;i<26;i++)
      fscanf(fi,"%d" ,&a[i]);
    dp[0]=1;
    for(i=1;i<=n;i++){
       j=i-1;
       x=a[A[i]];
       d[i]=n+1;
       while(j>=1&&x>=i-j){
           dp[i]+=dp[j];
           dp[i]%=MOD;
           len[i]=std::max(std::max(len[j],i-j),len[i]);
           d[i]=std::min(d[i],d[j]+1);
           x=std::min(x,a[A[j]]);
           j--;
       }
       if(x>=i){
          dp[i]++;
          dp[i]%=MOD;
          len[i]=i;
          d[i]=1;
       }
     //  printf("\n");
    }
    fprintf(fout,"%d\n%d\n%d" ,dp[n],len[n],d[n]);
 //   fclose(fi);
 //   fclose(fout);
    return 0;
}