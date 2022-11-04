#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
pair<ll,char>s[MAXN],t[MAXN];
int nxt[MAXN];
void kmp(pair<ll,char>str[],int len)
{
    memset(nxt,-1,sizeof(nxt));
    for(int i=0;i<len-1;i++)
    {
        int p=nxt[i];
        while(p!=-1 && str[i+1]!=str[p+1])p=nxt[p];
        nxt[i+1]=p+(str[i+1]==str[p+1]);
    }
}
ll solve(pair<ll,char>s[],int lens,pair<ll,char>t[],int lent)
{
    ll res=0;
    kmp(t,lent);
    int p=-1;
    if(lent==0 && s[0].second==t[0].second && s[0].first>=t[0].first
        && s[-1].second==t[-1].second && s[-1].first>=t[-1].first)res++;
    for(int i=0;i<lens;i++)
    {
        while(p!=-1 && s[i]!=t[p+1])p=nxt[p];
        if(p+1<lent && s[i]==t[p+1])p++;
        if(p==lent-1)
        {
            if(s[i+1].second==t[p+1].second && s[i+1].first>=t[p+1].first
               && s[i-p-1].second==t[-1].second && s[i-p-1].first>=t[-1].first)res++;
            p=nxt[p];
        }
    }
    return res;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll l;
    char c[5];
    for(int i=0;i<n;i++)
    {
        scanf("%I64d-%s",&l,c);
        s[i]=make_pair(l,*c);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%I64d-%s",&l,c);
        t[i]=make_pair(l,*c);
    }
    int now=0;
    for(int i=0;i+1<n;i++)
    {
        if(s[i+1].second==s[now].second)
            s[now].first+=s[i+1].first;
        else s[++now]=s[i+1];
    }
    n=now+1;
    now=0;
    for(int i=0;i+1<m;i++)
    {
        if(t[i+1].second==t[now].second)
            t[now].first+=t[i+1].first;
        else t[++now]=t[i+1];
    }
    m=now+1;
    if(m==1)
    {
        ll res=0;
        for(int i=0;i<n;i++)
            if(s[i].second==t[0].second)
                res+=max(0LL,s[i].first-t[0].first+1);
        return 0*printf("%I64d",res);
    }
    printf("%I64d",solve(s+1,n-2,t+1,m-2));
    return 0;
}