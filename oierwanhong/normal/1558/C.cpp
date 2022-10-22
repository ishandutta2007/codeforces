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
const int MAXN = 5011;
int a[MAXN],p[MAXN];
std::vector<int>res;
void Rev(int x){res.push_back(x),std::reverse(a+1,a+x+1);}
int main()
{
	int task=read();
	while(task--)
	{
		res.clear();
		bool fail=0;
		int n=read();
		for(int i=1;i<=n;++i)
		{
			a[i]=read(),p[i]=i;
			if((a[i]&1)!=(i&1))fail=1;
		}
		if(fail){puts("-1");continue;}
		for(int i=n;i>1;--i)
		{
			if(i&1)
			{
					int j=0;
					for(j=1;j<i&&a[j]!=i;++j);
					int p=0;
					for(p=1;p<i&&a[p]!=i-1;++p);
					if(p<j)Rev(j),p=j-p+1,j=1,Rev(p-1),j=p-1;
					else Rev(j),j=1,Rev(p-1),j=p-1;
						res.push_back(j+2);
						std::reverse(a+1,a+j+3);
						res.push_back(3);
						std::reverse(a+1,a+4);
						res.push_back(i);
						std::reverse(a+1,a+i+1);
			}
			else if(a[i]!=i)std::cerr<<"ERR!\n"<<std::endl;
		}
			printf("%d\n",int(res.size()));
			for(int i=0;i<res.size();++i)printf("%d ",res[i]);
			puts("");
	}
	return 0;
}