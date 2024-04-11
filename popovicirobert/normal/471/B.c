#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int val,nr;
}robert;
robert v[2000];
int rsort(const void *a,const void *b){
    if(((*(robert*)a).val)<((*(robert*)b).val))
        return -1;
    if(((*(robert*)a).val)>((*(robert*)b).val))
        return 1;
    return ((*(robert*)a).nr)-((*(robert*)b).nr);
}
int main()
{
    int i,n,aux,s,start,fac,j;
    scanf("%d" ,&n);
    for(i=0;i<n;i++){
       scanf("%d" ,&v[i].val);
       v[i].nr=i+1;
    }
    qsort(v,n,sizeof(robert),rsort);
    s=i=0;
    while(i<n){
        start=i;
        while(i<n-1&&v[i].val==v[i+1].val)
            i++;
        if((i-start+1)>2||s>3)
            i=n;
        else{
            fac=1;
            for(j=2;j<=(i-start+1);j++)
              fac=fac*j;
            if(i-start+1==1)
                fac--;
            s=s+fac;
        }
        i++;
        start=i;
    }
    if(i==n&&s<3)
        printf("NO");
    else{
        printf("YES\n");
        for(i=0;i<n;i++)
            printf("%d " ,v[i].nr);
        printf("\n");
        i=0;
        while(v[i].val!=v[i+1].val)
            i++;
        aux=v[i].nr;
        v[i].nr=v[i+1].nr;
        v[i+1].nr=aux;
        i++;
        for(j=0;j<n;j++)
            printf("%d " ,v[j].nr);
        printf("\n");
        while(v[i].val!=v[i+1].val)
            i++;
        aux=v[i].nr;
        v[i].nr=v[i+1].nr;
        v[i+1].nr=aux;
        for(j=0;j<n;j++)
            printf("%d " ,v[j].nr);
    }
    return 0;
}