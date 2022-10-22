//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 200011
char a[MAXN];
ll row[MAXN],col[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        scanf("%s",a+1);
        ll n=strlen(a+1),row_cnt=0,col_cnt=0;
        for(ll i=1;i<=n;++i)
        {
            if(a[i]=='W')row[++row_cnt]=1;
            else if(a[i]=='S')row[++row_cnt]=-1;
            else if(a[i]=='A')col[++col_cnt]=-1;
            else col[++col_cnt]=1;
        }
        ll minv=0,maxv=0,cur=0,row_len,row_f,col_len,col_f;
        for(ll i=1;i<=row_cnt;++i)//work row
            cur+=row[i],umax(maxv,cur),umin(minv,cur);
        row_f=row_len=maxv-minv+1;
        ll tmpmin=0,tmpmax=0,flag=0;
        cur=0;
        for(ll i=1;i<=row_cnt;++i)
        {
            cur+=row[i];
            if(cur==maxv&&!flag)flag=1,--cur,umin(tmpmin,cur-1);
            umax(tmpmax,cur),umin(tmpmin,cur);
        }
        umin(row_f,tmpmax-tmpmin+1);
        tmpmin=0,tmpmax=0,flag=0;
        cur=0;
        for(ll i=1;i<=row_cnt;++i)
        {
            cur+=row[i];
            if(cur==minv&&!flag)flag=1,++cur,umax(tmpmax,cur+1);
            umax(tmpmax,cur),umin(tmpmin,cur);
        }
        umin(row_f,tmpmax-tmpmin+1);
        /////work col
        minv=maxv=0;cur=0;
        for(ll i=1;i<=col_cnt;++i)
            cur+=col[i],umax(maxv,cur),umin(minv,cur);
        col_f=col_len=maxv-minv+1;
        tmpmin=0,tmpmax=0,flag=0;
        cur=0;
        for(ll i=1;i<=col_cnt;++i)
        {
            cur+=col[i];
            if(cur==maxv&&!flag)flag=1,--cur,umin(tmpmin,cur-1);
            umax(tmpmax,cur),umin(tmpmin,cur);
        }
        umin(col_f,tmpmax-tmpmin+1);
        tmpmin=0,tmpmax=0,flag=0;
        cur=0;
        for(ll i=1;i<=col_cnt;++i)
        {
            cur+=col[i];
            if(cur==minv&&!flag)flag=1,++cur,umax(tmpmax,cur+1);;
            umax(tmpmax,cur),umin(tmpmin,cur);
        }
        umin(col_f,tmpmax-tmpmin+1);
        printf("%lld\n",min(row_f*col_len,row_len*col_f));
    }
    return 0;
}