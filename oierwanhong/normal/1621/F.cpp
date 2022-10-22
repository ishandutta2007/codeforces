#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011;
char s[MAXN];
pii a[MAXN];
ll A,B,C;
std::vector<int>ex,border,merge;
ll Odd(ll p0,ll p1)
{
	ll k=min(p0,p1),d0=k;
	ll res=k*(A+B),pref=0;
	p0-=k,p1-=k;
	if(B>=C)
	{
		for(auto x:ex)
			if(d0>=(x-1))++pref,d0-=x-1;
		pref*=(B-C);
		res+=pref;
	}
	if(p0)return res+A;
	if(B>=C)
	{
		d0=k,res-=pref;
		//printf("Odd,d0=%lld,p0=%lld,p1=%lld\n",d0,p0,p1);
		merge=ex;
		for(int i=0;i<p1&&i<border.size();++i)merge.emplace_back(border[i]);
		std::sort(merge.begin(),merge.end());
		ll nowf=0;
		for(auto x:merge)
			if(d0>=(x-1))++nowf,d0-=(x-1);
		//printf("nowf=%lld\n",nowf);
		nowf*=B-C;
		res+=nowf;
	}
	return res;
}
ll Even(ll p0,ll p1)
{
	ll k=min(p0,p1);
	ll res=k*(A+B);
	p0-=k,p1-=k;
	if(!p1)return res;
	--p1,res+=B;
	if(B>=C)
	{
		merge=ex;
		for(int i=0;i<p1&&i<border.size();++i)merge.emplace_back(border[i]);
		std::sort(merge.begin(),merge.end());
		ll nowf=0;
		ll d0=k;
		for(auto x:merge)
			if(d0>=(x-1))++nowf,d0-=x-1;
		nowf*=(B-C);
		res+=nowf;
	}
	return res;
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		A=read(),B=read(),C=read();
		scanf("%s",s+1);
		int top=0;
		for(int i=1;i<=n;++i)
			if(top&&(s[i]-'0')==a[top].first)++a[top].second;
			else a[++top]=pii(s[i]-'0',1);
		ll p0=0,p1=0;
		ex.clear(),border.clear();
		for(int i=1;i<=top;++i)
			if(a[i].first==0)
			{
				p0+=a[i].second-1;
				if(1<i&&i<top)ex.emplace_back(a[i].second);
				else border.emplace_back(a[i].second);
			}
			else
			{
				p1+=a[i].second-1;
			}
		std::sort(ex.begin(),ex.end()),std::sort(border.begin(),border.end());
		printf("%lld\n",max(Odd(p0,p1),Even(p0,p1)));
	}
	return 0;
}