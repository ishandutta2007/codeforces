#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1000000007;
int n,m,p;
char s[1000005];
char t[1000005];
bool y[1000005];
int nxt[1000005];
void kmp()
{
    memset(nxt,-1,sizeof(nxt));
    nxt[0]=-1;
    for(int i=0;i<p-1;i++)
    {
        int q=nxt[i];
        while(q!=-1)
        {
            if(s[q+1]==s[i+1])
            {
                nxt[i+1]=q+1;
                break;
            }
            q=nxt[q];
        }
        if(q==-1)nxt[i+1]=(s[i+1]==s[0] ? 0 : -1);
    }
}
bool judge()
{
    int q=-1;
    for(int i=0;i<n;i++)
    {
        while(q!=-1 && s[q+1]!=t[i])q=nxt[q];
        q+=(s[q+1]==t[i]);
        if(i>=p-1 && y[i-p+1] && q<p-1)return 0;
    }
    return 1;
}
ll fast_pow(ll a,int k)
{
    ll res=1LL;
    while(k>0)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    p=strlen(s);
    int in;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&in);
        y[in-1]=1;
    }
    int loc=p,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(y[i])loc=0;
        if(loc<p)
        {
            t[i]=s[loc];
            loc++;
        }
        else
        {
            t[i]='$';
            cnt++;
        }
    }
    kmp();
    if(judge())
    {
        printf("%I64d\n",fast_pow(26LL,cnt));
    }
    else printf("0\n");
    return 0;
}