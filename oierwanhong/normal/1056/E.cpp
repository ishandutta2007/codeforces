//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
typedef int ll;
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
#define MAXN 1000001
ll sa[MAXN],rk[MAXN],tp[MAXN],c[MAXN];
char s[MAXN],t[MAXN];
void radix_sort(ll n,ll m)
{
    for(ll i=1;i<=m;++i)c[i]=0;
    for(ll i=1;i<=n;++i)++c[rk[i]];
    for(ll i=1;i<=m;++i)c[i]+=c[i-1];
    for(ll i=n;i;--i)sa[c[rk[tp[i]]]--]=tp[i];
}
void make_SA(ll n,ll m=128)
{
    for(ll i=1;i<=n;++i)rk[i]=s[i],tp[i]=i;
    radix_sort(n,m);
    for(ll k=1;k<=n;k<<=1)
    {
        ll cur=0;
        for(ll i=n-k+1;i<=n;++i)tp[++cur]=i;
        for(ll i=1;i<=n;++i)
            if(sa[i]>k)tp[++cur]=sa[i]-k;
        radix_sort(n,m);
        std::swap(rk,tp);
        cur=1,rk[sa[1]]=1;
        for(ll i=2;i<=n;++i)
        {
            if(tp[sa[i]]!=tp[sa[i-1]]||tp[sa[i]+k]!=tp[sa[i-1]+k])++cur;
            rk[sa[i]]=cur;
        }
        if(cur>=n)break;
        m=cur;
    }
}
ll height[MAXN];
void make_height(ll n)
{
    ll k=0;
    for(ll i=1;i<=n;++i)
    {
        if(k>0)--k;
        ll j=sa[rk[i]-1];
        while(s[i+k]==s[j+k])++k;
        height[rk[i]]=k;
    }
}
struct ST
{
    ll t[21][MAXN],lg[MAXN];
    void build(ll* arr,ll n)
    {
        lg[1]=0;
        for(ll i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
        for(ll i=1;i<=n;++i)t[0][i]=arr[i];
        for(ll i=1;i<=lg[n];++i)
            for(ll j=1;j+(1<<i)-1<=n;++j)
                t[i][j]=min(t[i-1][j],t[i-1][j+(1<<(i-1))]);
    }
    ll Qmin(ll l,ll r)
    {
    	if(l>r)std::swap(l,r);
    	++l;
        ll k=lg[r-l];
        return min(t[k][l],t[k][r-(1<<k)+1]);
    }
}st;
int main()
{
    scanf("%s%s",t+1,s+1);
    ll lent=strlen(t+1),lens=strlen(s+1),cnt0=0;
    make_SA(lens),make_height(lens);
    st.build(height,lens);
    for(ll i=1;i<=lent;++i)cnt0+=(t[i]=='0');
    ll ans=0;
    if(cnt0==lent)
    {
    	if(lens%cnt0==0)
    	{
    		ll i=lens/cnt0,pos=i+1,flag=1;
    		for(ll j=2;j<=lent;pos+=i,++j)
    			if(st.Qmin(rk[1],rk[pos])<i)flag=0;
    		if(flag)++ans;
		}
		printf("%d",ans);
		return 0;
	}
    else if(cnt0==0)
    {
    	if(lens%(lent-cnt0)==0)
    	{
    		ll i=lens/(lent-cnt0),pos=i+1,flag=1;
    		for(ll j=2;j<=lent;pos+=i,++j)
    			if(st.Qmin(rk[1],rk[pos])<i)flag=0;
    		if(flag)++ans;
		}
		printf("%d",ans);
		return 0;
	}
    for(ll i=1;i*cnt0<=lens;++i)
    {
        if((lens-i*cnt0)%(lent-cnt0))continue;
        ll start0=0,start1=0,pos=1,flag=1;
        ll k=(lens-i*cnt0)/(lent-cnt0);
        for(ll j=1;j<=lent;++j)
        {
            if(t[j]=='0')
            {
                if(!start0)start0=pos;
                else if(st.Qmin(rk[start0],rk[pos])<i)flag=0;
                pos+=i;
            }
            else
            {
                if(!start1)start1=pos;
                else if(st.Qmin(rk[start1],rk[pos])<k)flag=0;
                if(!k)flag=0;
                pos+=k;
            }
        }
        if(flag&&(i!=k||st.Qmin(rk[start0],rk[start1])<i))++ans;
    }
    printf("%d",ans);
    return 0;
}