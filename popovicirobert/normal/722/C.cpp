#include <cstdio>
#define INF 10000000000000000LL
#define MAXN 100000
struct Data{
   long long sum;
   long long sufix;
   long long prefix;
   long long ssm;
   inline void reset(long long val){
       sum=ssm=prefix=sufix=val;
   }
};
Data aint[4*MAXN+1];
inline long long getmax(long long a,long long b){
    if(a>b) return a;
    return b;
}
void update(int nod,int left,int right,int poz,long long val){
    if(left==right)
       aint[nod].reset(val);
    else{
       int med=(left+right)/2;
       if(poz<=med)
          update(2*nod,left,med,poz,val);
       else
          update(2*nod+1,med+1,right,poz,val);
       aint[nod].ssm=getmax(aint[2*nod].ssm,getmax(aint[2*nod+1].ssm,aint[2*nod].sufix+aint[2*nod+1].prefix));
       if(aint[nod].ssm<-INF)
         aint[nod].ssm=-INF;
       aint[nod].prefix=getmax(aint[2*nod].prefix,aint[2*nod].sum+aint[2*nod+1].prefix);
       if(aint[nod].prefix<-INF)
         aint[nod].prefix=-INF;
       aint[nod].sufix=getmax(aint[2*nod+1].sufix,aint[2*nod+1].sum+aint[2*nod].sufix);
       if(aint[nod].sufix<-INF)
         aint[nod].sufix=-INF;
       aint[nod].sum=aint[2*nod].sum+aint[2*nod+1].sum;
       if(aint[nod].sum<-INF)
         aint[nod].sum=-INF;
    }
}
long long ans,s;
void query(int nod,int left,int right,int l,int r){
    if(l<=left&&right<=r){
       ans=getmax(ans,getmax(aint[nod].ssm,aint[nod].prefix+s));
       s=getmax(s+aint[nod].sum,aint[nod].sufix);
    }
    else{
       int med=(left+right)/2;
       if(l<=med)
         query(2*nod,left,med,l,r);
       if(med<r)
         query(2*nod+1,med+1,right,l,r);
    }
}
int main(){
  // FILE*fi,*fout;
   int i,n,x,j;
   //fi=fopen("ultimulcartus.in" ,"r");
  // fout=fopen("ultimulcartus.out" ,"w");
   scanf("%d" ,&n);
   for(i=1;i<=n;i++){
      scanf("%d" ,&x);
      update(1,1,n,i,x);
   }
   for(j=1;j<=n;j++){
      scanf("%d" ,&x);
      update(1,1,n,x,-INF);
      ans=0;
      s=0;
      query(1,1,n,1,n);
      printf("%I64d\n" ,ans);
   }
  // fclose(fi);
 //  fclose(fout);
   return 0;
}