#include <bits/stdc++.h>
#define MAXN 100
bool v[MAXN+1];
int sol[MAXN+1];

int main(){
    FILE*fi,*fout;
    int i,n,k;
    char ch;
   // fi=fopen("C.in" ,"r");
 //   fout=fopen("C.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&k);
    fgetc(fi);
    for(i=1;i<=n-k+1;i++){
       ch=fgetc(fi);
       if(ch=='Y')
         v[i]=1;
       else
         v[i]=0;
       while(isalpha(ch))
          ch=fgetc(fi);
    }
    for(i=1;i<k;i++)
      sol[i]=i;
    for(i=1;i<=n-k+1;i++){
      if(v[i]==1)
          sol[i+k-1]=i+k;
      else
          sol[i+k-1]=sol[i];
    }
    for(i=1;i<=n;i++){
        int x=sol[i];
        int cnt=0;
        while(x>0){
            cnt++;
            if(cnt==1)
                fprintf(fout,"%c" ,x%26+'A');
            else
                fprintf(fout,"%c" ,x%26+'a')  ;
            x/=26;
        }
        fprintf(fout," ");
    }
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}