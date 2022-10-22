#pragma GCC optimize("Ofast")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
#define push_back emplace_back
/**********/
const int MAXN = 2000011;
int a[MAXN],b[MAXN],m[MAXN];
int res[MAXN];
struct one
{
	int l,r,dex;
	one(){}
	one(int l,int r,int dex):l(l),r(r),dex(dex) {}
	bool operator< (const one& you)const{return r<you.r;}
};
std::vector<one>seq[MAXN];
int stk[MAXN],top=0;
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)
		{
			a[i]=read(),b[i]=read(),m[i]=read();
			int k=a[i]+b[i]-m[i];
			stk[++top]=k,seq[k].emplace_back(one(max(a[i]-m[i],0),a[i]-max(m[i]-b[i],0),i));
		}
		int ans=0;
		while(top)
		{
			int x=stk[top--];
			if(seq[x].empty())continue;
			std::sort(seq[x].begin(),seq[x].end());
			int lst=-1;
			for(auto r:seq[x])
			{
				if(lst<r.l)++ans,lst=r.r;
				res[r.dex]=lst;
			}
			seq[x].clear();
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)printf("%d %d\n",a[i]-res[i],m[i]-(a[i]-res[i]));
	}
	return 0;
}