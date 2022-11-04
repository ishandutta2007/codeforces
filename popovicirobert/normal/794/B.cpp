#include <bits/stdc++.h>

int main(){
    FILE*fi,*fout;
    int i;
    double n,H,aria,s;
    //fi=fopen("B.in" ,"r");
    //fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%lf%lf" ,&n,&H);
    aria=(H*1.0)/2.0;
    s=0;
    for(i=1;i<n;i++){
       s+=aria/n;
       double b=sqrt((2*s)/H);
       fprintf(fout,"%lf " ,b*H);
    }
    //fclose(fi);
    //fclose(fout);
    return 0;
}