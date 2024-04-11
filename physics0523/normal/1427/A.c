#include<stdio.h>
#include<stdlib.h>

int sortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
void swap(int *a,int *b){int c;c=(*a);(*a)=(*b);(*b)=c;}

void prarr(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%d",arr[i]);
  }
  printf("\n");
  return;
}

int main(){
  int t;
  scanf("%d",&t);
  int a[64],n;
  while(t>0){
    t--;
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    qsort(a,n,sizeof(int),sortfncsj);
    int r=0,fl=0;
    for(int i=0;i<n;i++){
      r+=a[i];
      if(r==0){fl=1;break;}
    }
    if(fl==0){puts("YES");prarr(a,n);continue;}
    int p=0,q=n-1;
    while(p<q){
      swap(&a[p],&a[q]);
      p++;q--;
    }
    //prarr(a,n);
    r=0;fl=0;
    for(int i=0;i<n;i++){
      r+=a[i];
      if(r==0){fl=1;break;}
    }
    if(fl==0){puts("YES");prarr(a,n);continue;}
    puts("NO");
  }
}