#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=3e18;
const int M=50010;
const int N=50010;
int n,m,a,b,ans=inf,ff[M];
int f[M],sum1,sum2,sum;
struct node
{
	int u,v,w1,w2;
}e[N],v[M];
bool cmp1(node a,node b){return a.w1<b.w1;}
bool cmp2(node a,node b){return a.w2<b.w2;}

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int find2(int x){return ff[x]==x?x:ff[x]=find2(ff[x]);}

signed main()
{
	n=read(),m=read(),a=read(),b=read();
	for (int i=1;i<=n;i++)f[i]=i;
	for (int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w1=read(),e[i].w2=read();
	sort(e+1,e+1+m,cmp1);
	for (int i=1;i<=m;i++)
	{
		if (find(e[i].u)!=find(e[i].v))
			v[++sum]=e[i],f[find(e[i].u)]=find(e[i].v);
		else
		{
			for (int j=1;j<=n;j++)ff[j]=j;
			v[++sum]=e[i];int kkk=0;
			sort(v+1,v+1+sum,cmp2);
			for (int j=1;j<=sum;j++)
				if (find2(v[j].u)!=find2(v[j].v))
					v[++kkk]=v[j],ff[find2(v[j].u)]=find2(v[j].v);
			sum=kkk;
		}
		if (sum==n-1)
		{
			sum1=sum2=0;
			for (int j=1;j<=sum;j++)
				sum1=max(sum1,v[j].w1),sum2=max(sum2,v[j].w2);
			ans=min(ans,a*sum1+b*sum2);
		}
	}cout<<(ans==inf?-1:ans)<<endl;
	return 0;
}