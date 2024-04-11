#include <bits/stdc++.h>
#define MAXN 500000
std::vector <char> v[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n,j,p,l;
    char a;
   // fi=fopen("D.in" ,"r");
    //fout=fopen("D.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    fgetc(fi);
    for(i=1;i<=n;i++){
        a=fgetc(fi);
        while(isalpha(a)||a=='#'){
            v[i].push_back(a);
            a=fgetc(fi);
        }
    }
    for(i=n;i>1;i--){
        p=0;
        l=std::min(v[i].size(),v[i-1].size());
        while(p<l&&v[i][p]==v[i-1][p])
          p++;
        if(p==l){
            if(v[i].size()!=v[i-1].size()&&v[i].size()<v[i-1].size()){
                while(p<v[i-1].size()){
                  v[i-1][p]='?';
                  p++;
                }
            }
        }
        else
            if(v[i][p]<v[i-1][p]){
                while(p<v[i-1].size()){
                    v[i-1][p]='?';
                    p++;
                }
            }
    }
    for(i=1;i<=n;i++){
        fprintf(fout,"#");
        j=1;
        while(j<v[i].size()&&v[i][j]!='?'){
            fprintf(fout,"%c" ,v[i][j]);
            j++;
        }
        fprintf(fout,"\n");
    }
    //fclose(fi);
   // fclose(fout);
    return 0;
}