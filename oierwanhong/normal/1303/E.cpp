//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
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
#define MAXN 411
ll f[MAXN][MAXN];
bool check1(const str& s,const str& t)
{
	ll it=0;
	for(ll i=0;i<s.size();++i)
	{
		if(s[i]==t[it])++it;
		if(it==t.size())return 1;
	}
	return 0;
}
bool check2(const str& s,const str& t1,const str& t2)
{
	memset(f,-1,sizeof f);
	f[0][0]=0;
	for(ll i=0;i<s.size();++i)
		for(ll j=0;j<=t1.size();++j)
			if(f[i][j]>=0)
			{
				ll cur=f[i][j];
				if(j<t1.size() && s[i]==t1[j])umax(f[i+1][j+1],cur);
				if(cur<t2.size() && s[i]==t2[cur])umax(f[i+1][j],cur+1);
				umax(f[i+1][j],f[i][j]);
			}
	return f[s.size()][t1.size()]==t2.size();
}
void solve()
{
	str s,t,t1,t2;
	std::cin>>s>>t;
	if(check1(s,t))
	{
		puts("YES");return;
	}
	for(ll i=1;i<t.size();++i)
	{
		t1=t.substr(0,i);
		t2=t.substr(i);
		if(check2(s,t1,t2))
		{
			puts("YES");return;
		}
	}
	puts("NO");
}
int main()
{
	ll task=read();
	while(task--)solve();
	return 0;
}