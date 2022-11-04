#include <cstdio>
#define SQRTA 40000
#define MAXN 1000000
#define INF 100000000000000000LL
int v[MAXN+1],n;
long long d[MAXN+1][3],a,b;
inline long long getmin(long long a,long long b)
{
    if(a>b) return b;
    return a;
}
inline long long cauta(int x){
    int j,e;
    long long i=2,min;
    min=INF;
    while(i*i<=x){
        e=0;
        while(x%i==0){
            x/=i;
            e++;
        }
        if(e>0){
            for(j=1; j<=n; j++){
                if(v[j]%i==0){
                    d[j][0]=d[j-1][0];
                    d[j][1]=getmin(d[j-1][1]+a,d[j-1][0]+a);
                    d[j][2]=getmin(d[j-1][1],d[j-1][2]);
                }
                else if((v[j]-1)%i==0||(v[j]+1)%i==0){
                    d[j][0]=d[j-1][0]+b;
                    d[j][1]=getmin(d[j-1][1]+a,d[j-1][0]+a);
                    d[j][2]=getmin(d[j-1][1]+b,d[j-1][2]+b);
                }
                else{
                    d[j][0]=INF;
                    d[j][1]=getmin(d[j-1][1]+a,d[j-1][0]+a);
                    d[j][2]=INF;
                }
            }
            if(min>d[n][1])
              min=d[n][1];
            if(min>d[n][2])
              min=d[n][2];
            if(min>d[n][0])
               min=d[n][0];
            for(j=0; j<=n; j++)
                d[j][0]=d[j][1]=d[j][2]=0;
        }
        i++;
    }
    if(x>1){
       i=x;
         for(j=1; j<=n; j++){
                if(v[j]%i==0){
                    d[j][0]=d[j-1][0];
                    d[j][1]=getmin(d[j-1][1]+a,d[j-1][0]+a);
                    d[j][2]=getmin(d[j-1][1],d[j-1][2]);
                }
                else if((v[j]-1)%i==0||(v[j]+1)%i==0){
                    d[j][0]=d[j-1][0]+b;
                    d[j][1]=getmin(d[j-1][1]+a,d[j-1][0]+a);
                    d[j][2]=getmin(d[j-1][1]+b,d[j-1][2]+b);
                }
                else{
                    d[j][0]=INF;
                    d[j][1]=getmin(d[j-1][1]+a,d[j-1][0]+a);
                    d[j][2]=INF;
                }
            }
            if(min>d[n][1])
              min=d[n][1];
            if(min>d[n][2])
              min=d[n][2];
            if(min>d[n][0])
               min=d[n][0];
        for(j=0; j<=n; j++)
            d[j][0]=d[j][1]=d[j][2]=0;
    }
    return min;
}
int main(){
   // FILE*fi,*fout;
    int i;
    long long min;
   // fi=fopen("gcd.in" ,"r");
   // fout=fopen("gcd.out" ,"w");
    scanf("%d%I64d%I64d" ,&n,&a,&b);
    for(i=1; i<=n; i++)
        scanf("%d" ,&v[i]);
    min=INF;
    min=getmin(min,cauta(v[1]));
    min=getmin(min,cauta(v[1]-1));
    min=getmin(min,cauta(v[1]+1));
    min=getmin(min,cauta(v[n]));
    min=getmin(min,cauta(v[n]+1));
    min=getmin(min,cauta(v[n]-1));
    printf("%I64d\n" ,min);
   // fclose(fi);
   // fclose(fout);
    return 0;
}