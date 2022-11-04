#include <stdio.h>
#include <stdlib.h>
int poz[100001],p1[100001],p2[100001],neg[100001];
void myqsort(int begin,int end,int *v,int *x1){
    int b=begin,e=end,aux,pivot=v[(b+e)/2],aux1;
    while(b<=e){
        while(v[b]<pivot) b++;
        while(v[e]>pivot) e--;
        if(b<=e){
            aux=v[b];aux1=x1[b];
            v[b]=v[e];x1[b]=x1[e];
            v[e]=aux;x1[e]=aux1;
            b++;e--;
        }
    }
    if(begin<e) myqsort(begin,e,v,x1);
    if(b<end) myqsort(b,end,v,x1);
}
int main(){
    int n,n1,s,n2,i,x,a;
    scanf("%d" ,&n);
    n1=n2=0;
    for(i=0;i<n;i++){
        scanf("%d%d" ,&x,&a);
        if(x>0){
            poz[n1]=a;
            p1[n1++]=x;
        }
        else{
            neg[n2]=a;
            p2[n2++]=x;
        }
    }
    if(n1>0)
       myqsort(0,n1-1,p1,poz);
    if(n2>0)
       myqsort(0,n2-1,p2,neg);
    s=0;
    if(n1>n2){
        for(i=0;i<n2+1;i++)
            s+=poz[i];
        for(i=0;i<n2;i++)
            s+=neg[i];
    }
    else{
        for(i=n2-1;i>=n2-1-n1;i--)
            s+=neg[i];
        for(i=0;i<n1;i++)
            s+=poz[i];
    }
    printf("%d" ,s);
    return 0;
}