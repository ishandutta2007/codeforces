#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=100111;
const int maxv=5111;
namespace BIT
{
	int mark[maxv][maxv],timer,bit[maxv][maxv];
	void add(int x,int y,int v)
	{
//		printf("add %d %d v= %d\n",x,y,v);
		for(int i=x;i<maxv;i+=i&-i)for(int j=y;j<maxv;j+=j&-j)
		{
			if(mark[i][j]!=timer)
			{
				mark[i][j]=timer;
				bit[i][j]=v;
			}
			else bit[i][j]+=v;
		}
	}
	int query(int x,int y)
	{
		int ret=0;
		for(int i=x;i;i-=i&-i)for(int j=y;j;j-=j&-j)if(mark[i][j]==timer)ret+=bit[i][j];
		return ret;
	}
}

struct qt
{
	int tp,x,y,z;
	qt(int k1=0,int k2=0,int k3=0,int k4=0){tp=k1;x=k2;y=k3;z=k4;}
} qv[maxn];
int n,q,ans[maxn];

void solve(int l,int r,int piv)
{
	while(l<=r&&qv[l].tp!=piv)l++;
	while(l<=r&&qv[r].tp!=0)r--;
	if(l>r)return;
	
	vector<pii> vs;
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;i++)if(qv[i].tp==piv)vs.pb(mp(-qv[i].x-qv[i].y-qv[i].z,i));
	for(int i=mid+1;i<=r;i++)if(qv[i].tp==0)vs.pb(mp(-qv[i].x-qv[i].y,i));
	sort(vs.begin(),vs.end());
	BIT::timer++;
	for(int i=0;i<(int)vs.size();i++)
	{
		int id=vs[i].ss;
		if(qv[id].tp==piv)BIT::add(qv[id].x,qv[id].y,1);
		else ans[id]+=BIT::query(qv[id].x,qv[id].y);
	}
	solve(l,mid,piv);
	solve(mid+1,r,piv);
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1,tp,x,y,z;i<=q;i++)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d%d%d%d",&tp,&x,&y,&z);
			qv[i]=qt(tp,x,y,z);
		}
		else
		{
			tp=0;scanf("%d%d",&x,&y);
			qv[i]=qt(tp,x,y,i);
		}
	}
	
	solve(1,q,1);
	for(int i=1;i<=q;i++)qv[i].y=n-qv[i].y+1;
	solve(1,q,2);
	for(int i=1;i<=q;i++)qv[i].x=n-qv[i].x+1;
	solve(1,q,4);
	for(int i=1;i<=q;i++)qv[i].y=n-qv[i].y+1;
	solve(1,q,3);
	
	for(int i=1;i<=q;i++)if(qv[i].tp==0)printf("%d\n",ans[i]);
	
	return 0;
}