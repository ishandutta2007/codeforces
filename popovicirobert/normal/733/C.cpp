#include <bits/stdc++.h>
#define MAXN 500
int A[MAXN+1];
int B[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,j,n,m,sum,k,cnt,p,max;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++)
      fscanf(fi,"%d" ,&A[i]);
    fscanf(fi,"%d" ,&m);
    for(i=1;i<=m;i++)
      fscanf(fi,"%d" ,&B[i]);
    i=p=1;
    while(i<=n){
       j=i;
       sum=0;
       cnt=0;
       while(j<=n&&sum+A[j]<B[p]){
          sum+=A[j];
          if(A[j]==A[i])
            cnt++;
          j++;
       }
       if(A[j]==A[i])
          cnt++;
       if(sum+A[j]==B[p]&&(cnt<j-i+1||i==j))
          p++;
       else{
          fprintf(fout,"NO");
          return 0;
       }
       i=j+1;
    }
    if(p<=m){
       fprintf(fout,"NO");
       return 0;
    }
    fprintf(fout,"YES\n");
    int nr=0;
    i=p=1;
    while(i<=n){
       j=i;
       sum=0;
       cnt=0;
       max=0;
       while(j<=n&&sum+A[j]<B[p]){
          sum+=A[j];
          if(A[j]>max)
            max=A[j];
          j++;
       }
       if(A[j]>max)
         max=A[j];
       int poz=-1;
       for(k=i;k<=j;k++){
          if(max==A[k]){
             if(k-1>=i&&A[k-1]<A[k])
               poz=k;
             if(k+1<=j&&A[k+1]<A[k])
               poz=k;
          }
       }
      if(i<j)
       if(A[poz-1]<A[poz]){
          k=poz-1;
          while(k>=i){
             fprintf(fout,"%d L\n" ,nr+k-i+2);
             k--;
          }
          k=poz+1;
          while(k<=j){
             fprintf(fout,"%d R\n" ,nr+1);
             k++;
          }
       }
       else{
          k=poz+1;
          while(k<=j){
             fprintf(fout,"%d R\n" ,nr+poz-i+1);
             k++;
          }
          k=poz-1;
          while(k>=i){
             fprintf(fout,"%d L\n" ,nr+k-i+2);
             k--;
          }
       }
       p++;
       nr++;
       i=j+1;
    }
    //fclose(fi);
    //fclose(fout);
    return 0;
}