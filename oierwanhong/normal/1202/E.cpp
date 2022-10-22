#include<bits/stdc++.h>
typedef long long ll;
#define MAXN 200011
struct ACAM
{
    ll t[MAXN][26],val[MAXN],fail[MAXN];
    ll cnt=0;
    void insert(char* a,ll n)
    {
        ll u=0;
        for(ll i=1;i<=n;++i)
        {
            ll &v=t[u][a[i]-'a'];
            if(!v)v=++cnt;
            u=v;
        }
        ++val[u];
    }
    void build()
    {
        std::queue<ll>q;
        for(ll i=0;i<26;++i)
            if(t[0][i])q.push(t[0][i]);
        while(!q.empty())
        {
            ll u=q.front();q.pop();
            for(ll i=0;i<26;++i)
            {
                ll &v=t[u][i];
                if(v)fail[v]=t[fail[u]][i],val[v]+=val[fail[v]],q.push(v);
                else v=t[fail[u]][i];
            }
        }
    }
    void Query(char* a,ll n,ll f[])
    {
        ll u=0;
        for(ll i=1;i<=n;++i)
        {
            u=t[u][a[i]-'a'];
            f[i]=val[u];
        }
    }
}ac,Rac;
ll f1[MAXN],f2[MAXN];
char a[MAXN],b[MAXN];
int main()
{
    scanf("%s",a+1);
    ll n,la=strlen(a+1);std::cin>>n;
    while(n--)
    {
        scanf("%s",b+1);
        ll lb=strlen(b+1);
        ac.insert(b,lb);
        std::reverse(b+1,b+lb+1);Rac.insert(b,lb);
    }
    ac.build();Rac.build();
    ac.Query(a,la,f1);std::reverse(a+1,a+la+1);Rac.Query(a,la,f2);
    ll ans=0;
    for(ll i=1;i<=la;++i)ans+=f1[i]*f2[la-i];
    printf("%lld",ans);
    return 0;
}