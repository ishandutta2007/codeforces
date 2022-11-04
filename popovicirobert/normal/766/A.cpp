#include <bits/stdc++.h>
#define MAXN 100000
char A[MAXN+1];
char B[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n,m;
 //   fi=fopen("A.in" ,"r");
 //   fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%s%s" ,&A,&B);
    n=strlen(A);
    m=strlen(B);
    if(n!=m)
      fprintf(fout,"%d" ,std::max(n,m));
    else{
      i=0;
      while(i<n&&A[i]==B[i])
        i++;
      if(i==n)
         fprintf(fout,"-1");
      else
         fprintf(fout,"%d" ,n);
    }
 //   fclose(fi);
 //   fclose(fout);
    return 0;
}