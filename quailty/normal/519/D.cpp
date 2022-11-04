#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x[30];
struct sufix
{
    int loc;
    ll val;
    char las;
}sum[100005];
char s[100005];
bool cmp(sufix a,sufix b)
{
    if(a.las==b.las)
    {
        if(a.val==b.val)return a.loc<b.loc;
        else return a.val<b.val;
    }
    else return a.las<b.las;
}
bool cmp2(sufix a,sufix b)
{
    return a.las==b.las ? a.val<b.val : a.las<b.las;
}
ll C(ll k)
{
    return k*(k-1)/2;
}
int main()
{
    for(int i=0;i<26;i++)
        scanf("%I64d",&x[i]);
    scanf("%s",s);
    int n=strlen(s);
    for(int i=1;i<=n;i++)
    {
        sum[i].val=sum[i-1].val+x[s[i-1]-'a'];
        sum[i].las=s[i-1];
        sum[i].loc=i;
    }
    sort(sum+1,sum+n+1,cmp);
    ll ans=0;
    /*
    for(int i=1;i<=n;i++)
    {
        printf("%I64d %c\n",sum[i].val,sum[i].las);
    }
    */
    for(int i=1;i<=n;i++)
    {
        sufix t;
        t.val=sum[i].val+x[sum[i].las-'a'];
        t.las=sum[i].las;
        sufix s;
        ll cnt=upper_bound(sum+1,sum+n+1,t,cmp2)
                -lower_bound(sum+1,sum+n+1,t,cmp2);
        if(cnt==0)continue;
        s=*lower_bound(sum+1,sum+n+1,t,cmp2);
        s.loc=sum[i].loc+1;
        cnt=upper_bound(sum+1,sum+n+1,t,cmp2)
            -lower_bound(sum+1,sum+n+1,s,cmp);
        //printf("%I64d\n",cnt);
        ans+=cnt;
    }
    printf("%I64d",ans);
    return 0;
}