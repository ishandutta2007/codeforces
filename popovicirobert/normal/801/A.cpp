#include <bits/stdc++.h>
char v[10000];
int main(){
    FILE*fi,*fout;
    int i,n,ans;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%s" ,&v);
    n=strlen(v);
    ans=0;
    for(i=1;i<n;i++)
       if(v[i-1]=='V'&&v[i]=='K')
         ans++;
    if(v[0]=='K'&&v[1]=='K')
       ans++;
    else{
    for(i=1;i<n;i++)
     if(v[i-1]=='V'&&v[i]=='V'&&v[i+1]!='K'){
         ans++;
         break;
     }
     else if(v[i-1]=='K'&&v[i]=='K'&&v[i+1]=='K'){
         ans++;
         break;
     }
    }
    fprintf(fout,"%d" ,ans);
    //fclose(fi);
    //fclose(fout);
    return 0;
}