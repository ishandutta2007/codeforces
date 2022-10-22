#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
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
std::multiset<ll>s,t;
int main()
{
	int task=read();
	while(task--)
	{
		s.clear(),t.clear();
		int n=read();
		ll sum=0;
		for(int i=1;i<=n;++i)
		{
			ll x=read();
			sum+=x,s.insert(x);
		}
		t.insert(sum);
		bool fail=0;
		while(t.size())
		{
			ll x=*--t.end();
			t.erase(--t.end());
			auto p=s.lower_bound(x);
			if(p==s.end())
			{
				ll y=x/2,z=(x+1)/2;
				t.insert(y),t.insert(z);
			}
			else if((*--s.end())>x){fail=1;break;}
			else s.erase(p);
		}
		puts(fail?"NO":"YES");
	}
	return 0;
}