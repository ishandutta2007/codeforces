#include <bits/stdc++.h>
char A[1000];
char B[1000];
char C[1000];
int main(){
    FILE*fi,*fout;
    int i,n,flag;
    //fi=fopen("B.in" ,"r");
    //fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%s" ,&A);
    fscanf(fi,"%s" ,&C);
    n=strlen(A);
    flag=1;
    for(i=0;i<n&&flag;i++){
        if(A[i]<C[i])
          flag=0;
        else{
            if(A[i]==C[i])
               B[i]='z';
            else
               B[i]=C[i];
        }
    }
    if(flag==0)
         fprintf(fout,"-1");
    else
        for(i=0;i<n;i++)
           fprintf(fout,"%c" ,B[i]);
    //fclose(fi);
    //fclose(fout);
    return 0;
}