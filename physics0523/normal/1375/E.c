#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){int c;c=(*a);(*a)=(*b);(*b)=c;}

typedef struct{
int val;
int node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
if(((sd*)a)->node < ((sd*)b)->node){return -1;}
if(((sd*)a)->node > ((sd*)b)->node){return 1;}
return 0;
}

int main(){
  int tg,n,a[1024],p[1024],iv[1024],r,i,j;
  sd dat[1024];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    dat[i].val=a[i];
    dat[i].node=i;
  }
  r=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(a[i]>a[j]){r++;}
    }
  }
  printf("%d\n",r);
  qsort(dat,n,sizeof(dat[0]),sdsortfnc);
  for(i=0;i<n;i++){
    p[dat[i].node]=i;
    iv[i]=dat[i].node;
  }
  for(i=n-1;i>=0;i--){
    while(p[i]!=i){
      tg=p[i];
      printf("%d %d\n",iv[tg+1]+1,i+1);
      swap(&iv[tg+1],&iv[tg]);
      p[iv[tg]]=tg;
      p[iv[tg+1]]=tg+1;
      //for(j=0;j<n;j++){printf("[%d](%d)",p[j],iv[j]);}printf("\n");
    }
  }
  return 0;
}