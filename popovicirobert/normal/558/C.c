#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000
#define MAXM 10000000
int cod[MAXN],gasit[MAXN+1],op[MAXN+1],v[MAXN],num[MAXN+1],vf[MAXN+1];
int main(){
    int i,n,x,b,e,nr,min,max;
    scanf("%d" ,&n);
    max=0;
    for(i=0;i<n;i++){
        scanf("%d" ,&v[i]);
        if(v[i]>max)
           max=v[i];
    }
    for(i=0;i<n;i++){
        gasit[v[i]]++;
        cod[0]=v[i];
        vf[v[i]]=i+1;
        op[0]=0;
        b=0;
        e=1;
        do{
            nr=cod[b];
            x=op[b];
            b++;
            if(nr>0&&vf[nr/2]!=i+1){
                op[e]=x+1;
                cod[e]=nr/2;
                num[nr/2]+=op[e];
                gasit[cod[e]]++;
                vf[nr/2]=i+1;
                e++;
            }
            if(nr*2<=max&&vf[nr*2]!=i+1){
                op[e]=x+1;
                cod[e]=nr*2;
                num[2*nr]+=op[e];
                vf[2*nr]=i+1;
                gasit[cod[e]]++;
                e++;
            }
        }while(b<e);
    }
    min=MAXM;
    for(i=0;i<=max;i++)
       if(gasit[i]==n&&min>num[i])
          min=num[i];
    printf("%d" ,min);
    return 0;
}