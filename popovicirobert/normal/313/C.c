#include <stdio.h>
#include <stdlib.h>
#define MAXN 1500
int v[MAXN*MAXN];
long long s[MAXN*MAXN];
void myqsort(int begin,int end){
    int b=begin,e=end,aux,pivot=v[(b+e)/2];
    while(b<=e){
        while(v[b]<pivot) b++;
        while(v[e]>pivot) e--;
        if(b<=e){
            aux=v[b];
            v[b]=v[e];
            v[e]=aux;
            b++;e--;
        }
    }
    if(begin<e) myqsort(begin,e);
    if(b<end) myqsort(b,end);
}
int main(){
   // FILE*fi,*fout;
    int i,j,n,st,x,p4;
    long long sum;
 //   fi=fopen("ilya.in" ,"r");
  //  fout=fopen("ilya.out" ,"w");
    scanf("%d" ,&n);
    sum=0;
    for(i=0;i<n;i++)
        scanf("%d" ,&v[i]);
    myqsort(0,n-1);
    for(i=0;i<n;i++)
        s[i+1]=s[i]+v[i];
    st=0;
    p4=n;
    while(n>st){
        sum+=s[n]-s[st];
        st=n-p4/4;
        p4/=4;
    }
    printf("%I64d" ,sum);
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}