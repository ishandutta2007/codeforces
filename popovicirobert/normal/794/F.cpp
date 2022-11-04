#include <bits/stdc++.h>
#define MAXN 100002
struct Aint{
   long long fr[10];
   char lazy[10];
}aint[4*MAXN+1];
inline void add(int nod,int val){
    long long p10=1;
    while(val>0){
       aint[nod].fr[val%10]+=p10;
       val/=10;
       p10*=10;
    }
}
inline void refresh(int nod){
    memset(aint[nod].fr,0,sizeof(aint[nod].fr));
    for(int i=0;i<10;i++)
      aint[nod].fr[i]=aint[2*nod].fr[i]+aint[2*nod+1].fr[i];
}
inline void build(int nod,int left,int right,int pos,int val){
    for(int i=0;i<10;i++)
      aint[nod].lazy[i]=i;
    if(left==right)
       add(nod,val);
    else{
       int med=(left+right)/2;
       if(pos<=med)
         build(2*nod,left,med,pos,val);
       else
         build(2*nod+1,med+1,right,pos,val);
       refresh(nod);
    }
}
inline void prop(int nod){
    if(2*nod+1<=4*MAXN)
     for(int j=0;j<2;j++)
       for(int i=0;i<10;i++)
         aint[2*nod+j].lazy[i]=aint[nod].lazy[aint[2*nod+j].lazy[i]];
}
long long sum[10];
void solve_lazy(int nod){
    memset(sum,0,sizeof(sum));
    prop(nod);
    for(int i=0;i<10;i++)
       sum[aint[nod].lazy[i]]+=aint[nod].fr[i];
    for(int i=0;i<10;i++){
       aint[nod].fr[i]=sum[i];
       aint[nod].lazy[i]=i;
    }
}
void update(int nod,int left,int right,int l,int r,char x,char y){
    solve_lazy(nod);
    if(l<=left&&right<=r){
       aint[nod].lazy[x]=y;
       solve_lazy(nod);
    }
    else{
       solve_lazy(nod);
       int med=(left+right)/2;
       if(l<=med)
         update(2*nod,left,med,l,r,x,y);
       if(med<r)
         update(2*nod+1,med+1,right,l,r,x,y);
       solve_lazy(2*nod);
       solve_lazy(2*nod+1);
       refresh(nod);
    }
}
long long ans;
inline void MakeAns(int nod){
    for(int i=0;i<10;i++)
      ans+=1LL*aint[nod].fr[i]*i;
}
void query(int nod,int left,int right,int l,int r){
    solve_lazy(nod);
    if(l<=left&&right<=r)
       MakeAns(nod);
    else{
       int med=(left+right)/2;
       if(l<=med)
         query(2*nod,left,med,l,r);
       if(med<r)
         query(2*nod+1,med+1,right,l,r);
       solve_lazy(2*nod);
       solve_lazy(2*nod+1);
       refresh(nod);
    }
}
int main(){
    FILE*fi,*fout;
    int i,n,q,val,l,r,tip,x,y;
   //fi=fopen("F.in" ,"r");
   // fout=fopen("F.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d %d " ,&n,&q);
    for(i=1;i<=n;i++){
       fscanf(fi,"%d " ,&val);
       build(1,1,n,i,val);
    }
    while(q>0){
       q--;
       fscanf(fi,"%d %d %d " ,&tip,&l,&r);
       if(tip==1){
          fscanf(fi,"%d %d " ,&x,&y);
          update(1,1,n,l,r,x,y);
       }
       else{
          ans=0;
          query(1,1,n,l,r);
          fprintf(fout,"%I64d\n" ,ans);
       }
    }
   // fclose(fi);
   // fclose(fout);
    return 0;
}