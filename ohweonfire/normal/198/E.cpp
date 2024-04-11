#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=250111;
int X,Y,P,n,x[maxn],y[maxn],p[maxn],m[maxn],ord[maxn];
LL d[maxn],R,r[maxn];
bool have[maxn];

bool cmp(int x,int y){return d[x]<d[y];}

queue<int> q[maxn];
void add(int x){for(int i=m[x];i<maxn;i+=i&-i)q[i].push(x);}
void del(int x,LL y)
{
	for(;x;x-=x&-x)
	{
		while(!q[x].empty()&&d[q[x].front()]<=y)
		{
			int tmp=q[x].front();q[x].pop();
			if(!have[tmp])
			{
				have[tmp]=1;
				del(p[tmp],r[tmp]);
			}
		}
	}
}

int main()
{
	vector<int> vs;
	scanf("%d%d%d%lld%d",&X,&Y,&P,&R,&n);R*=R;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%lld",x+i,y+i,m+i,p+i,r+i);
		d[i]=(LL)(x[i]-X)*(x[i]-X)+(LL)(y[i]-Y)*(y[i]-Y);
		r[i]*=r[i];
		vs.pb(m[i]);
	}
	vs.pb(-1);sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=1;i<=n;i++)
	{
		m[i]=lower_bound(vs.begin(),vs.end(),m[i])-vs.begin();
		p[i]=upper_bound(vs.begin(),vs.end(),p[i])-vs.begin()-1;
		ord[i]=i;
	}
	P=upper_bound(vs.begin(),vs.end(),P)-vs.begin()-1;
	sort(ord+1,ord+n+1,cmp);
	for(int i=1;i<=n;i++)add(ord[i]);
	del(P,R);
	int ans=0;
	for(int i=1;i<=n;i++)if(have[i])ans++;
	printf("%d\n",ans);
	return 0;
}