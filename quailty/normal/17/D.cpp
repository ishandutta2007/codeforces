#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
char b[MAXN],n[MAXN];
int phi(int x)
{
    int res=x;
    for(int i=2;i*i<=x;i++)if(x%i==0)
    {
        res=res/i*(i-1);
        while(x%i==0)x/=i;
    }
    if(x>1)res=res/x*(x-1);
    return res;
}
int fp(int a,int k,int Mod)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res%Mod;
}
int cal(char *str,int Mod)
{
    int res=0;
    for(int i=0;str[i];i++)
        res=(10LL*res+str[i]-'0')%Mod;
    return res;
}
int main()
{
    int c;
    scanf("%s%s%d",b,n,&c);
    if(c==1)return 0*printf("1");
    int mb=cal(b,c),res=(mb+c-1)%c;
    int f=phi(c),t=0;
    for(int i=0;n[i];i++)
        t=min(1000000000LL,10LL*t+n[i]-'0');
    if(t-1<f)res=1LL*res*fp(mb,t-1,c)%c;
    else res=1LL*res*fp(mb,cal(n,f)+f-1,c)%c;
    return 0*printf("%d",(res+c-1)%c+1);
}