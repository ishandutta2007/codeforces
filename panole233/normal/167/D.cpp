#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod=1000000009;
int n,k,A,B,C,D,fa[100010],s[100010][2],m,f[100010][2],l,r,ma[100010],mi[100010];

struct node
{
	int x,y;
}a[100001];

int getmax(int a,int b) {return a>b?a:b;}
int getmin(int a,int b) {return a<b?a:b;}
bool cmp(node a,node b) {return a.y>b.y;}

void Dfs(int x,int i)
{
	if (a[i].x<a[x].x) 
	{
		if (s[x][0]) {Dfs(s[x][0],i); return;}
		fa[i]=x; s[x][0]=i;
	} else
	{
		if (s[x][1]) {Dfs(s[x][1],i); return;}
		fa[i]=x; s[x][1]=i;
	}
}

void dfs(int x)
{
	if (s[x][0]) dfs(s[x][0]);
	if (s[x][1]) dfs(s[x][1]);
	if (!s[x][0]&&!s[x][1]) f[x][0]=f[x][1]=0; else
	if (!s[x][0]) f[x][0]=f[s[x][1]][1],f[x][1]=f[s[x][1]][0]+1; else
	if (!s[x][1]) f[x][0]=f[s[x][0]][1],f[x][1]=f[s[x][0]][0]+1; else
	f[x][0]=f[s[x][0]][1]+f[s[x][1]][1],f[x][1]=getmax(f[s[x][0]][1]+f[s[x][1]][0],f[s[x][0]][0]+f[s[x][1]][1])+1;
	ma[x]=getmax(a[x].x,getmax(ma[s[x][0]],ma[s[x][1]]));
	mi[x]=getmin(a[x].x,getmin(mi[s[x][0]],mi[s[x][1]]));
}

pair<int,int> work(int x,int l,int r)
{
	if (!x) return make_pair(0,0);
	if (l>a[x].x) return work(s[x][1],l,r);
	if (r<a[x].x) return work(s[x][0],l,r);
	if (l<=mi[x]&&r>=ma[x]) return make_pair(f[x][0],f[x][1]);
	pair<int,int> ansl,ansr;
	if (ma[s[x][0]]<l&&mi[s[x][1]]>r) return make_pair(0,0);
	if (ma[s[x][0]]<l) 
	{
		ansr=work(s[x][1],a[x].x+1,r); 
		return make_pair(ansr.second,ansr.first+1);
	} 
	if (mi[s[x][1]]>r)
	{
		ansl=work(s[x][0],l,a[x].x-1);
		return make_pair(ansl.second,ansl.first+1);
	}
	ansl=work(s[x][0],l,a[x].x-1); ansr=work(s[x][1],a[x].x+1,r);
	return make_pair(ansl.second+ansr.second,getmax(ansl.first+ansr.second,ansl.second+ansr.first)+1);
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1; i<=k; i++) scanf("%d%d",&a[i].x,&a[i].y);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	for (int i=k+1; i<=n; i++) 
		a[i].x=(1ll*a[i-1].x*A+B)%mod,a[i].y=(1ll*a[i-1].y*C+D)%mod;
	ma[0]=-1; mi[0]=mod+1;
	sort(a+1,a+1+n,cmp); fa[1]=0; s[1][0]=s[1][1]=0;
	for (int i=2; i<=n; i++) Dfs(1,i),s[i][0]=s[i][1]=0; dfs(1);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d%d",&l,&r); pair<int,int> ans=work(1,l,r);
		printf("%d\n",getmax(ans.first,ans.second));
	}
	return 0;
}