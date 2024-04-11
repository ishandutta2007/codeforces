#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::string str;
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
const int MAXN = 200011;
char s[MAXN],sa[MAXN],sb[MAXN];
std::map<str,int>mp;
std::map<pii,int>f;
int len[MAXN*4];
std::vector<int>a[MAXN*4];
int large[MAXN],dex[MAXN], lcnt;
pii b[MAXN];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1),tot=0;
	for(int i=1;i<=n;++i)
	{
		str cur;
		for(int j=i;j<=i+3;++j)
		{
			cur+=s[j];
			if(!mp.count(cur))mp[cur]=++tot,len[tot]=cur.size();
			a[mp[cur]].emplace_back(j);
		}
	}
	int m=read();
	while(m--)
	{
		scanf("%s%s",sa+1,sb+1);
		int la=strlen(sa+1),lb=strlen(sb+1);
		str ssa,ssb;
		for(int i=1;i<=la;++i)ssa+=sa[i];
		for(int i=1;i<=lb;++i)ssb+=sb[i];
		if(!mp.count(ssa)||!mp.count(ssb)){puts("-1");continue;}
		int x=mp[ssa],y=mp[ssb];
		if(a[x].size()>a[y].size())std::swap(x,y),std::swap(la,lb);
		if(f.count(pii(x,y))){printf("%d\n",f[pii(x,y)]);continue;}
		int ans=n;
		for(auto p:a[x])
		{
			auto it=std::lower_bound(a[y].begin(),a[y].end(),p);
			if(it!=a[y].end())umin(ans,(*it)-p+la);
			if(it!=a[y].begin())umin(ans,p-*(--it)+lb);
		}
		printf("%d\n",f[pii(x,y)]=max(ans,max(la,lb)));
	}
	return 0;
}