#include <cstdio>
long long rez[200001];
int v[200001];
long long sp[400001];
int main(){
  //  FILE*fi,*fout;
    int i,n,x;
    long long p,sum,max;
  //  fi=fopen("F.in" ,"r");
 //   fout=fopen("F.out" ,"w");
    scanf("%d" ,&n);
    for(i=1;i<=n;i++){
       scanf("%d" ,&x);
       v[i]=x;
       sp[x]++;
    }
    for(i=1;i<=400000;i++)
      sp[i]+=sp[i-1];
    max=0;
    for(i=1;i<=n;i++)
      if(rez[v[i]]==0){
         p=2*v[i];
         sum=0;
         while(p<=400000){
            sum=sum+(sp[p-1]-sp[p-v[i]-1])*(p-v[i]);
            p+=v[i];
         }
         if(sum==0)
           sum=-1;
         rez[v[i]]=sum;
         if(max<rez[v[i]])
           max=rez[v[i]];
      }
    printf("%I64d" ,max);
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}