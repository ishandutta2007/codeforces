#include <bits/stdc++.h>

int main(){
    FILE*fi,*fout;
    long long a,b;
   // fi=fopen("A.in" ,"r");
  //  fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%I64d%I64d" ,&a,&b);
    int cnt=0;
    while(a<=b){
        a*=3;
        b*=2;
        cnt++;
    }
    fprintf(fout,"%d" ,cnt);
    //fclose(fi);
    //fclose(fout);
    return 0;
}