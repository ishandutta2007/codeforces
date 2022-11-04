#include <bits/stdc++.h>
#define MAXVAL 1000000000000000LL
#define MAXN 100000
long long power[100];
std::map <long long,int> s;
inline long long myabs(long long x){
   if(x<0)
     return -x;
   return x;
}
int main(){
    int i,m,n,x,j;
    long long ans,sum,k;
    scanf("%d%I64d" ,&n,&k);
    power[0]=1;
    i=1;
    while(myabs(power[i-1]*k)<=MAXVAL&&myabs(k)!=1){
       power[i]=power[i-1]*k;
       i++;
    }
    m=i-1;
    if(k==-1)
       power[++m]=-1;
    s[0]=1;
    sum=0;
    ans=0;
    for(i=1;i<=n;i++){
       scanf("%d" ,&x);
       sum+=x;
       for(j=0;j<=m;j++)
        ans+=s[sum-power[j]];
       s[sum]++;
    }
    printf("%I64d" ,ans);
    return 0;
}