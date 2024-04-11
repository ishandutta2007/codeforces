#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
int a[11][MAXN],lim[11], n,m;
struct one
{
	std::vector<int>b;
	int sum;
	bool operator< (const one& you)const{return sum<you.sum;}
};
std::priority_queue<one>q;
std::set<std::vector<int>>s,ban;
void insert(std::vector<int> b)
{
	if(s.find(b)!=s.end())return;
	s.insert(b);
	int sum=0;
	for(int i=0;i<n;++i)sum+=a[i][b[i]];
	q.push({b,sum});
}
int main()
{
	n=read();
	for(int i=0;i<n;++i)
	{
		lim[i]=read();
		for(int j=1;j<=lim[i];++j)a[i][j]=read();
	}
	int m=read();
	while(m--)
	{
		std::vector<int>tp(n);
		for(int i=0;i<n;++i)tp[i]=read();
		ban.insert(tp);
	}
	std::vector<int>cur(n);
	for(int i=0;i<n;++i)cur[i]=lim[i];
	insert(cur);
	while(q.size())
	{
		cur=q.top().b;
		if(ban.find(cur)==ban.end())
		{
			for(int i=0;i<n;++i)printf("%d ",cur[i]);
			puts("");
			return 0;
		}
		q.pop();
		for(int i=0;i<n;++i)
			if(cur[i]>1)
			{
				--cur[i];
				insert(cur);
				++cur[i];
			}
	}
	fprintf(stderr,"ERR!!!");
	return 0;
}