//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
#define MAXN 51

ll ax[MAXN],ay[MAXN];
ll n;
void check(ll lx,ll rx,ll ly,ll ry)
{
	ll x=-1,y=-1,c1=0,c2=0,c3=0,c4=0;
	for(ll i=1;i<=4*n+1;++i)
		if((ax[i]<lx||ax[i]>rx||ay[i]<ly||ay[i]>ry))
		{
			if(x>=0)return;
			x=ax[i],y=ay[i];
		}
		else 
		{
			bool f=0;
			if(ax[i]==lx)++c1,f=1;
			if(ax[i]==rx)++c2,f=1;
			if(ay[i]==ly)++c3,f=1;
			if(ay[i]==ry)++c4,f=1;
			if(!f)
			{
				if(x>=0)return;
				x=ax[i],y=ay[i];
			}
		}
	if(x<0||c1<n||c2<n||c3<n||c4<n)return;
	std::cout<<x<<" "<<y;
}
int main()
{
	n=read();
	for(ll i=1;i<=4*n+1;++i)ax[i]=read(),ay[i]=read();
	for(ll lx=0;lx<MAXN;++lx)
		for(ll rx=lx+n;rx<MAXN;++rx)
			for(ll ly=0;ly<MAXN;++ly)
				for(ll ry=ly+n;ry<MAXN;++ry)
					check(lx,rx,ly,ry);
	return 0;
}