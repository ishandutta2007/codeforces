#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2000005;
const int Mod=51123987;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(char *s,int len)
{
    int l=0;
    Ma[l++]='$',Ma[l++]='#';
    for(int i=0;i<len;i++)
        Ma[l++]=s[i],Ma[l++]='#';
    Ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;i++)
    {
        Mp[i]=(mx>i ? min(Mp[2*id-i],mx-i) : 1);
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
        if(i+Mp[i]>mx)mx=i+Mp[i],id=i;
    }
}
char s[MAXN];
int st[MAXN*2],ed[MAXN*2];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    Manacher(s+1,n);
    for(int i=1;i<=2*n+1;i++)
    {
        st[i-Mp[i]+1]++,st[i+1]--;
        ed[i]++,ed[i+Mp[i]]--;
    }
    for(int i=1;i<=2*n+1;i++)
        st[i]+=st[i-1],ed[i]+=ed[i-1];
    for(int i=1;i<=n;i++)
        st[i]=st[i*2],ed[i]=ed[i*2];
    int res=0;
    for(int i=1;i<=n;i++)
        ed[i]=(ed[i]+ed[i-1])%Mod;
    for(int i=1;i<n;i++)
        res=(res+1LL*ed[i]*st[i+1])%Mod;
    res=(1LL*ed[n]*(ed[n]-1)/2%Mod-res+Mod)%Mod;
    return 0*printf("%d",res);
}