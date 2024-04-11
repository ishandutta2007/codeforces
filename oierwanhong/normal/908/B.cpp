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
const int MAXN= 5011;
const int mx[]={0,1,0,-1},my[]={1,0,-1,0};
int p[MAXN];
char a[MAXN][MAXN],op[MAXN];
bool vis[MAXN][MAXN];
pii Q[MAXN];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	scanf("%s",op+1);
	int l=strlen(op+1);
	int sx=0,sy=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]=='S')sx=i,sy=j;
	a[sx][sy]='.';
	for(int i=0;i<4;++i)p[i]=i;
	int ans=0;
	do
	{
		int x=sx,y=sy,flag=0;
		for(int i=1;i<=l;++i)
		{
			x+=mx[p[op[i]-'0']],y+=my[p[op[i]-'0']];
			if(a[x][y]=='E'){flag=1;break;}
			if(a[x][y]!='.')break;
		}
		ans+=flag;
	}while(std::next_permutation(p,p+4));
	printf("%d\n",ans);
	return 0;
}