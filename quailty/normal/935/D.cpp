#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
int fp(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int a[MAXN],b[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    swap(a,b);
    int res=0,now=1;
    for(int i=1;i<=n;i++)
    {
        int les,equ;
        if(a[i]==0)
        {
            if(b[i]==0)
            {
                les=1LL*(m-1)*fp(2*m,Mod-2)%Mod;
                equ=fp(m,Mod-2);
            }
            else
            {
                les=1LL*(b[i]-1)*fp(m,Mod-2)%Mod;
                equ=fp(m,Mod-2);
            }
        }
        else
        {
            if(b[i]==0)
            {
                les=1LL*(m-a[i])*fp(m,Mod-2)%Mod;
                equ=fp(m,Mod-2);
            }
            else
            {
                if(a[i]==b[i])les=0,equ=1;
                else if(a[i]<b[i])les=1,equ=0;
                else break;
            }
        }
        res=(res+1LL*now*les)%Mod;
        now=1LL*now*equ%Mod;
    }
    return 0*printf("%d\n",res);
}