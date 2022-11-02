#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=1000010;
int n,sum[2][N],fa[N],siz[N],mx[N];
char st[N];
vector<int>g[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool check(int l,int r){return (sum[0][r]-sum[0][l-1]>0)+(sum[1][r]-sum[1][l-1]>0)<=1;}
int main()
{
	scanf("%d",&n);
	scanf("%s",st+1);
	rep(i,n)if(st[i]!='?')sum[st[i]-'0'][i]=1;
	rep(i,2)rep(j,n)sum[i-1][j]+=sum[i-1][j-1];
	g[1].pb(n);
	for(int i=n-1;i;i--)
	{
		int l=i,r=n+1;
		for(;l<r-1;)
		{
			int mid=(l+r)>>1;
			if(check(i,mid))l=mid;else r=mid;
		}
		g[l-i+1].pb(i);
	}
	rep(i,n+1)fa[i]=i;
	rep(i,n)
	{
		int now=1,ans=0;
		for(;now+i-1<=n;)
		{
			//if(check(now,now+i-1)){now+=i;ans++;continue;}
			now=find(now);
			if(now>n)break;
			now+=i;ans++;
		}
		printf("%d%c",ans," \n"[i==n]);
		for(auto j:g[i])fa[j]=find(j+1);
	}
    return 0;
}