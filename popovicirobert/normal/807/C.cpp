#include <bits/stdc++.h>

int main(){
    FILE*fi,*fout;
    int t;
    long long x,y,p,q;
   // fi=fopen("C.in" ,"r");
    //fout=fopen("C.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&t);
    while(t>0){
        t--;
        fscanf(fi,"%I64d%I64d%I64d%I64d" ,&x,&y,&p,&q);
        if(x*q==y*p)
          fprintf(fout,"0\n");
        else if(p==q||p==0)
          fprintf(fout,"-1\n");
        else{
          long long a=std::max(x/p+(x%p>0),std::max(y/q+(y%q>0),(y-x)/(q-p)+((y-x)%(q-p)!=0)));
          fprintf(fout,"%I64d\n" ,a*q-y);
        }
    }
    //fclose(fi);
    //fclose(fout);
    return 0;
}