#include <cstdio>
typedef long long ll;
ll fibo[70];
int ans[60];
int nxt=1;
int main()
{
    ll n,k;
    fibo[0]=fibo[1]=1;
    scanf("%I64d%I64d",&n,&k);
    int i,j,ind=0;
    for(i=2;i<=60;++i) fibo[i]=fibo[i-1]+fibo[i-2];
    for(i=1;i<n;++i){
        if(k>fibo[n-i]){
            k-=fibo[n-i];
            ans[ind++]=nxt+1;
            ans[ind++]=nxt;
            nxt+=2;
            i+=1;
        } else {
            ans[ind++]=nxt++;
        }
    }
    if(ind<n) ans[ind++]=nxt++;
    for(i=0;i<ind;++i) printf("%d ",ans[i]);
    return 0;
}