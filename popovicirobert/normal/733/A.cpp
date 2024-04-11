#include <bits/stdc++.h>
#define MAXN 1000
char v[MAXN+1];
inline bool ok(char ch){
   if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='Y')
     return 0;
   return 1;
}
int main(){
    FILE*fi,*fout;
    int n,ans,i,j;
    char ch;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    ch=fgetc(fi);
    v[0]='A';
    n=0;
    while(ch!='\n'){
       v[++n]=ch;
       ch=fgetc(fi);
    }
    v[n+1]='A';
    i=0;
    ans=0;
    while(i<=n){
       j=i+1;
       while(j<=n+1&&ok(v[j]))
          j++;
       ans=std::max(ans,j-i);
       i=j;
    }
    fprintf(fout,"%d" ,ans);
    //fclose(fi);
    //fclose(fout);
    return 0;
}