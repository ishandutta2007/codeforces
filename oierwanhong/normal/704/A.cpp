#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 600011;
bool used[MAXN];
std::vector<int>a[MAXN];
int main()
{
	int n=read(),m=read();
	int it=1,ans=0,all=0;
	while(m--)
	{
		int op=read();
		if(op==1)
		{
			++all,++ans;
			a[read()].push_back(all);
		}
		else if(op==2)
		{
			int x=read();
			for(auto y:a[x])
				if(!used[y])--ans,used[y]=1;
			a[x].clear();
		}
		else
		{
			int t=read();
			while(it<=t)
			{
				if(!used[it])--ans,used[it]=1;
				++it;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}