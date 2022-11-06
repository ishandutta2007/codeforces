#include <cstdio>
#define MAXN 500000
#define MAXNR 1000000
int v[MAXN],vf[MAXNR+1];
int main(){
    int poz1,poz2,b,e,max,nr,n,k,i;
    scanf("%d%d" ,&n,&k);
    for(i=0;i<n;i++)
        scanf("%d" ,&v[i]);
    b=e=nr=max=0;
    while(e<n){
        if(vf[v[e]]==0)
            nr++;
        vf[v[e]]++;
        while(nr>k){
            vf[v[b]]--;
            if(vf[v[b]]==0)
                nr--;
            b++;
        }
        if(max<e-b+1){
            max=e-b+1;
            poz1=b+1;
            poz2=e+1;
        }
        e++;
    }
    printf("%d %d" ,poz1,poz2);
    return 0;
}