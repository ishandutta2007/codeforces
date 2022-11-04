#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int x[10000005],f[10000005],ans[10000005];
int prime[670000],cnt;
bool not_prime[10000005];
void build_ans()
{
    for(int i=2;i<=10000000;i++){
        if(!not_prime[i]){
            prime[cnt++]=i;
            f[i]+=x[i];
            for(int j=2*i;j<=10000000;j+=i){
                not_prime[j]=1;
                f[i]+=x[j];
            }
        }
    }
    for(int i=1;i<=10000000;i++){
        ans[i]=ans[i-1]+f[i];
    }
}
int main()
{

    int n,m,_in;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&_in);
        x[_in]++;
    }
    build_ans();
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>10000000)a=10000000;
        if(b>10000000)b=10000000;
        printf("%d\n",ans[b]-ans[a-1]);
    }
    return 0;
}