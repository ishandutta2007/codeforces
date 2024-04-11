#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int MAXQ=10000000;
const int MAXL=14;
int vis[MAXQ],num[MAXL];
int change(int t)
{
    int now=0;
    while(t)
    {
        num[now++]=t%10;
        t/=10;
    }
    return now;
}
unordered_map<ll,int>mp[2][10];
void solve_right(ll n,ll &k)
{
    for(int i=1;i<MAXQ;i++)
    {
        int t=change(i),ok=1;
        if(t==2)ok&=(num[0]!=num[1]);
        for(int j=1;j<t-1;j++)
            ok&=((num[j]>num[j-1] && num[j]>num[j+1])
               ||(num[j]<num[j-1] && num[j]<num[j+1]));
        if(!ok)continue;
        vis[i]=1;
        k-=(i%n==0);
        if(k==0)
        {
            printf("%d",i);
            exit(0);
        }
        if(t==6 && num[t-1]>num[t-2])mp[0][0][i%n]++;
        else if(t==7)mp[num[t-1]>num[t-2]][num[t-1]][i%n]++;
    }
}
void get_res(ll n,ll &k,ll Mod,int lef)
{
    int len=7;
    while(lef)
    {
        num[len++]=lef%10;
        lef/=10;
    }
    for(int i=1;i<MAXQ;i++)
    {
        if(!vis[i])continue;
        int t=change(i),ok=1;
        while(t<7)num[t++]=0;
        t=len;
        for(int j=1;j<t-1;j++)
            ok&=((num[j]>num[j-1] && num[j]>num[j+1])
               ||(num[j]<num[j-1] && num[j]<num[j+1]));
        if(!ok)continue;
        k-=(i%n==Mod);
        if(k==0)
        {
            printf("%07d",i);
            exit(0);
        }
    }
}
void solve_left(ll n,ll &k)
{
    for(int i=1;i<MAXQ;i++)
    {
        if(!vis[i])continue;
        int t=change(i),ok=1;
        if(t==2)ok&=(num[0]!=num[1]);
        for(int j=1;j<t-1;j++)
            ok&=((num[j]>num[j-1] && num[j]>num[j+1])
               ||(num[j]<num[j-1] && num[j]<num[j+1]));
        if(!ok)continue;
        ll m=(n-1LL*i*MAXQ%n)%n,cnt=0;
        if(t==1)
        {
            for(int j=0;j<num[0];j++)
                if(mp[0][j].find(m)!=mp[0][j].end())
                    cnt+=mp[0][j][m];
            for(int j=num[0]+1;j<10;j++)
                if(mp[1][j].find(m)!=mp[1][j].end())
                    cnt+=mp[1][j][m];
        }
        else
        {
            int go=(num[1]>num[0]);
            if(go==0)for(int j=0;j<num[0];j++)
                if(mp[0][j].find(m)!=mp[0][j].end())
                    cnt+=mp[0][j][m];
            if(go==1)for(int j=num[0]+1;j<10;j++)
                if(mp[1][j].find(m)!=mp[1][j].end())
                    cnt+=mp[1][j][m];
        }
        if(k<=cnt)
        {
            printf("%d",i);
            get_res(n,k,m,i);
        }
        else k-=cnt;
    }
}
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    solve_right(n,k);
    solve_left(n,k);
    return 0*printf("-1");
}