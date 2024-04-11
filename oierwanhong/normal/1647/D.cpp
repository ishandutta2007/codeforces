#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;
typedef std::pair<int,int> pii;
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
std::map<pii,int>f;
std::vector<int>a;
void Add(int& x,int y)
{
	x+=y;
	if(x>3)x=3;
}
int main()
{
	int task=read();
	while(task--)
	{
		f.clear(),a.clear();
		ll n=read(),d=read();
		for(ll i=1;i*i<=n;++i)
			if(n%i==0)
			{
				ll t=i;
				if(t%d==0&&t%(d*d))a.emplace_back(t);
				if(i*i<n)
				{
					t=n/i;
					if(t%d==0&&t%(d*d))a.emplace_back(t);
				}
			}
		std::sort(a.begin(),a.end());
		int ans=0;
		Add(f[pii(n,n)],1);
		while(f.size())
		{
			auto it=--f.end();f.erase(--f.end());
			int rest=it->first.first,lst=it->first.second;
			//printf("Take F[%d,%d]=%d\n",rest,lst,it->second);
			if(rest==1)
			{
				Add(ans,it->second);
				continue;
			}
			for(auto x:a)
				if(rest%x==0&&lst>=x)Add(f[pii(rest/x,x)],it->second);
		}
		puts(ans>=2?"YES":"NO");
	}
	return 0;
}