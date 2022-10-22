#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
/**********/
#define MAXN 400011
struct edge{int v,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}

int c[MAXN],cur=0;
int Q[MAXN];
int main()
{
	int n=read();
	for(int i=1;i<n;++i){int u=read(),v=read();adde(u,v),adde(v,u);}
	int h=0,t=0;
	c[1]=1,Q[t++]=1;
	while(n--)
	{
		int x=read();
		if(c[x]!=c[Q[h]]){puts("No");return 0;}
		c[x]=-1;
		while(h<t&&c[Q[h]]==-1)++h;
		++cur;
		for(int i=last[x];i;i=e[i].nxt)
			if(!c[e[i].v])c[e[i].v]=cur,Q[t++]=e[i].v;
	}
	puts("Yes");
	return 0;
}