#include <bits/stdc++.h>
#define MAXN 100003
long long v[MAXN+1];
inline long long myabs(long long x){
   if(x<0)
      x=-x;
   return x;
}
int main(){
    FILE*fi,*fout;
    int i,n;
    long long t1,t2,t,x,ans,min;
  //  fi=fopen("B.in" ,"r");
  //  fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%I64d%I64d%I64d" ,&t1,&t2,&t);
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++)
     fscanf(fi,"%I64d" ,&v[i]);
    i=1;
    x=t1;
    if(v[1]>t1)
        x=v[1];
    min=(1LL<<60);
    while(i<=n){
      if(v[i]!=v[i-1]){
        if(i>1){
          if(x<=v[i]-1){
             if(x+t<=t2){
               min=0;
               ans=x;
               x=v[i];
             }
          }
          else if(min>x-(v[i]-1)){
             if(v[i]-1+t<=t2){
               min=x-(v[i]-1);
               ans=v[i]-1;
             }
          }
        }
     }
     x+=t;
      if(v[i]!=v[i+1]&&min>myabs(x-v[i])&&v[i]+t<=t2){
            min=myabs(x-v[i]);
            ans=v[i];
        }
        i++;
    }
    if(t1>=v[1]&&min>(t1-v[1]+1)){
        ans=v[1]-1;
        min=(t1-v[1]+1);
    }
    if(x+t<=t2){
        ans=x;
        min=0;
    }
    if(v[1]>t1){
        ans=t1;
        min=0;
    }
    fprintf(fout,"%I64d" ,ans);
    //fclose(fi);
   // fclose(fout);
    return 0;
}