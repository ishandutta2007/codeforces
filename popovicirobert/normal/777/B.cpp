#include <bits/stdc++.h>
#define MAXN 1000
char v[MAXN+1];
int vf1[20],vf2[20],vf[20];
int main(){
    FILE*fi,*fout;
    int ans1,ans2,i,x,n;
    char a;
  //  fi=fopen("B.in" ,"r");
  //  fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    fgetc(fi);
    a=fgetc(fi);
    i=0;
    while(isdigit(a)){
        vf1[a-'0']++;
        v[++i]=a-'0';
        a=fgetc(fi);
    }
    a=fgetc(fi);
    while(isdigit(a)){
        vf2[a-'0']++;
        vf[a-'0']++;
        a=fgetc(fi);
    }
    ans1=ans2=0;
    for(i=1;i<=n;i++){
       x=v[i];
       while(x<=9&&vf[x]==0)
          x++;
       if(x<=9)
         vf[x]--;
       else
         ans1++;
    }
    for(i=1;i<=n;i++){
       x=v[i]+1;
       while(x<=9&&vf2[x]==0)
          x++;
       if(x<=9){
         ans2++;
         vf2[x]--;
       }
    }
    fprintf(fout,"%d\n%d" ,ans1,ans2);
    //fclose(fi);
   // fclose(fout);
    return 0;
}