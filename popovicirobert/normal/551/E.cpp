#include <bits/stdc++.h>
#define val first
#define poz second
#define MAXN 500000
std::pair<long long,int> v[MAXN+1];
long long lazy[MAXN+1];
inline void sort(int l,int r){
    std::sort(v+l,v+r);
}
int main(){
    FILE*fi,*fout;
    int i,n,q,t,l,r,x;
   // fi=fopen("E.in" ,"r");
  //  fout=fopen("E.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&q);
    for(i=0;i<n;i++){
      fscanf(fi,"%I64d" ,&v[i].val);
      v[i].poz=i;
    }
    int len=sqrt(n);
    for(i=0;i<n;i+=len)
        sort(i,std::min(i+len,n));
    while(q){
      q--;
      fscanf(fi,"%d" ,&t);
      if(t==1){
         fscanf(fi,"%d%d%d" ,&l,&r,&x);
         l--;
         r--;
         int poz1=l/len,poz2=r/len;
         i=poz1*len;
         while(i<poz1*len+len){
             if(i<n&&v[i].poz>=l&&v[i].poz<=r)
               v[i].val+=x;
             i++;
         }
         l=i;
         sort(l-len,std::min(n,l));
         if(l<=r){
           i=poz2*len+len-1;
           while(i>=poz2*len){
              if(v[i].poz<=r&&v[i].poz>=l)
                v[i].val+=x;
              i--;
           }
           r=i;
           sort(r+1,std::min(n,r+len+1));
         }
         while(l<=r){
           lazy[l]+=x;
           l+=len;
         }
      }
      else{
         fscanf(fi,"%d" ,&x);
         int min=n;
         int max=-1;
         for(i=0;i<n;i+=len){
            int low=i-1;
            for(int pas=1<<17;pas;pas>>=1)
              if(low+pas<std::min(i+len,n)&&v[low+pas].val+lazy[i]<x)
                low+=pas;
            int high=i;
            for(int pas=1<<17;pas;pas>>=1)
              if(high+pas<std::min(i+len,n)&&v[high+pas].val+lazy[i]<=x)
                high+=pas;
            low++;
            if(low<std::min(n,i+len)&&v[low].val+lazy[i]==x){
                min=std::min(min,v[low].poz);
                max=std::max(max,v[high].poz);
            }
         }
         if(max==-1)
            fprintf(fout,"-1\n");
         else
            fprintf(fout,"%d\n" ,max-min);
      }
    }
   // fclose(fi);
  //  fclose(fout);
    return 0;
}