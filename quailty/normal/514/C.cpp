#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
ll thr[600005],sev[600005];
void build()
{
    thr[0]=1;
    sev[0]=1;
    for(int i=1;i<=600000;i++)
    {
        thr[i]=(thr[i-1]*3)%1000000007;
        sev[i]=(sev[i-1]*7)%1000000009;
    }
}
ll has(char ch[],ll bas,ll mod)
{
    int len=strlen(ch);
    int res=0;
    for(int i=0;i<len;i++)
        res=(res*bas+ch[i])%mod;
    return res;
}
char s[600005];
set<int>p,q;
int main()
{
    build();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        p.insert(has(s,3,1000000007));
        q.insert(has(s,7,1000000009));
    }
    for(int i=1;i<=m;i++)
    {
        bool isok=0;
        scanf("%s",s);
        int len=strlen(s);
        ll hasp=has(s,3,1000000007);
        ll hasq=has(s,7,1000000009);
        for(int j=0;j<len;j++)
        {
            if(s[j]=='a')
            {
                if(p.find((hasp+thr[len-1-j])%1000000007)!=p.end()
                   && q.find((hasq+sev[len-1-j])%1000000009)!=q.end())
                {
                    isok=1;
                    break;
                }
                if(p.find((hasp+2*thr[len-1-j])%1000000007)!=p.end()
                   && q.find((hasq+2*sev[len-1-j])%1000000009)!=q.end())
                {
                    isok=1;
                    break;
                }
            }
            else if(s[j]=='b')
            {
                if(p.find((hasp-thr[len-1-j]+1000000007)%1000000007)!=p.end()
                   && q.find((hasq-sev[len-1-j]+1000000009)%1000000009)!=q.end())
                {
                    isok=1;
                    break;
                }
                if(p.find((hasp+thr[len-1-j])%1000000007)!=p.end()
                   && q.find((hasq+sev[len-1-j])%1000000009)!=q.end())
                {
                    isok=1;
                    break;
                }
            }
            else if(s[j]=='c')
            {
                if(p.find((hasp-2*thr[len-1-j]+2*1000000007)%1000000007)!=p.end()
                   && q.find((hasq-2*sev[len-1-j]+2*1000000009)%1000000009)!=q.end())
                {
                    isok=1;
                    break;
                }
                if(p.find((hasp-thr[len-1-j]+1000000007)%1000000007)!=p.end()
                   && q.find((hasq-sev[len-1-j]+1000000009)%1000000009)!=q.end())
                {
                    isok=1;
                    break;
                }
            }
        }
        if(isok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}