#include <cstdio>
inline long long cauta(long long n){
    long long k=2,con=0;
    while(k*k*k<=n){
        con+=n/(k*k*k);
        k++;
    }
    return con;
}
int main(){
    long long pas,rez,m;
    scanf("%I64d" ,&m);
    rez=0;
    for(pas=1LL<<55;pas;pas>>=1)
      if(cauta(rez+pas)<m)
         rez+=pas;
    if(cauta(rez+1)!=m)
        rez=-2;
    printf("%I64d" ,rez+1);
    return 0;
}