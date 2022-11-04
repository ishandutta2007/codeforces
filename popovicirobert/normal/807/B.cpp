#include <bits/stdc++.h>
bool f[501];
inline void check(int s){
   int i=(s/50)%475;
   memset(f,0,sizeof(f));
   for(int j=1;j<=25;j++){
      i=(i*96+42)%475;
      f[26+i]=1;
   }
}
int main(){
    FILE*fi,*fout;
    int i,p,x,y;
    //fi=fopen("B.in" ,"r");
    //fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d" ,&p,&x,&y);
    int a=x;
    while(a>=y){
       check(a);
       if(f[p]==1){
          fprintf(fout,"0");
          return 0;
       }
       a-=50;
    }
    bool flag=1;
    int cnt=0;
    while(flag){
       if(x>=y){
          check(x);
          if(f[p]==1)
            flag=0;
          if(x-50>=y){
             check(x-50);
             if(f[p]==1)
                 flag=0;
          }
       }
       cnt++;
       x+=100;
    }
    fprintf(fout,"%d" ,cnt-1);
    //fclose(fi);
    //fclose(fout);
    return 0;
}