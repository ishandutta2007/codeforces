//Mo's algorithm
//https://codeforces.com/contest/86/problem/D
//https://blog.anudeep2011.com/mos-algorithm/
//https://ei1333.hateblo.jp/entry/2017/09/11/211011
//https://lumakernel.github.io/ecasdqina/algorithm/Mo
#include<stdio.h>
#include<stdlib.h>
#define psize 600

typedef struct{
  long long st;
  long long fi;
  long long id;
}query;

int qsortfnc(const void *a,const void *b){
  long long ast=(((query*)a)->st);
  long long afi=(((query*)a)->fi);
  long long bst=(((query*)b)->st);
  long long bfi=(((query*)b)->fi);
  ast/=psize;bst/=psize;
  if(ast<bst){return -1;}
  if(ast>bst){return 1;}
  if((ast&1ll)==0){
    if(afi<bfi){return -1;}
    if(afi>bfi){return 1;}
  }
  else{
    if(afi<bfi){return 1;}
    if(afi>bfi){return -1;}
  }
  return 0;
}

long long n;
long long arr[262144];
long long bk[1048576]={0};
long long res=0;
long long st,fi;

void mo_add(long long id){
  long long v=arr[id];
  res-=(v*bk[v]*bk[v]);
  bk[v]++;
  res+=(v*bk[v]*bk[v]);
}

void mo_rem(long long id){
  long long v=arr[id];
  res-=(v*bk[v]*bk[v]);
  bk[v]--;
  res+=(v*bk[v]*bk[v]);
}

long long mo_query(long long tst,long long tfi){
  if(!(fi<tst)){
    while(st<tst){mo_rem(st);st++;}
    while(tst<st){st--;mo_add(st);}
  }
  while(fi<tfi){fi++;mo_add(fi);}
  while(tfi<fi){mo_rem(fi);fi--;}

  while(st<tst){mo_rem(st);st++;}
  while(tst<st){st--;mo_add(st);}
  return res;
}

int main(){
  long long i,q,res[262144];
  query qa[262144];
  scanf("%lld%lld",&n,&q);
  for(i=1;i<=n;i++){scanf("%lld",&arr[i]);}
  for(i=0;i<q;i++){
    scanf("%lld%lld",&qa[i].st,&qa[i].fi);
    qa[i].id=i;
  }
  qsort(qa,q,sizeof(qa[0]),qsortfnc);
  mo_add(1);st=1;fi=1;
  for(i=0;i<q;i++){
    res[qa[i].id]=mo_query(qa[i].st,qa[i].fi);
  }
  for(i=0;i<q;i++){
    printf("%lld\n",res[i]);
  }
  return 0;
}