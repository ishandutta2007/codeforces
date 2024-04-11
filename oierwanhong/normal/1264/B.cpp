//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<deque>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
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
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
std::deque<ll>q;
void print()
{
	puts("YES");
	for(std::deque<ll>::iterator it=q.begin();it!=q.end();++it)printf("%lld ",*it);
}
int main()
{
	ll a=read(),b=read(),c=read(),d=read();
	ll tmp=min(c,d);c-=tmp,d-=tmp;
	for(ll i=1;i<=tmp;++i)q.push_back(3),q.push_back(2);
	if(d>1)
	{
		puts("NO");
		return 0;
	}
	if(d==1)
	{
		if(!a&&!b)
		{
			q.push_back(3);
			print();
		}
		else puts("NO");
		return 0;
	}
	////
	tmp=min(b,c);b-=tmp,c-=tmp;
	if(tmp)q.push_front(2),q.push_front(1),--tmp;
	for(ll i=1;i<=tmp;++i)q.push_back(1),q.push_back(2);
	if(c>0&&(q.empty()||q.back()!=2))q.push_back(2),--c;
	if(c>0&&(!q.empty()&&(q.front()==3||q.front()==1)))q.push_front(2),--c;
	if(c>0)
	{
		puts("NO");
		return 0;
	}
	tmp=min(a,b);a-=tmp,b-=tmp;
	for(ll i=1;i<=tmp;++i)q.push_back(1),q.push_back(0);
	if(b>0)q.push_back(1),--b;
	if(b>0&&(!q.empty()&&q.front()==2))q.push_front(1),--b;
	if(b>0)
	{
		puts("NO");
		return 0;
	}
	if(a>1)
	{
		puts("NO");
		return 0;
	}
	if(a==1)
	{
		if(q.empty()||q.front()==1)
		{
			q.push_front(0);
			print();
		}
		else puts("NO");
		return 0;
	}
	print();
	return 0;
}