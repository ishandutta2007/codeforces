#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 5010
using namespace std;
int t,n,d,fa[N],td,dep[N],sonsz[N],bmp;
vector<int> pd[110],no[110];
void dfs(int x,int md)
{
	td+=md;
	dep[x]=md;
	bmp=max(bmp,md);
	if(td>d)
	{
		return;
	}
	if((x<<1)<=n)
	{
		sonsz[x]++;
		fa[(x<<1)]=x;
		dfs((x<<1),md+1);
	}
	if((x<<1)+1<=n)
	{
		sonsz[x]++;
		fa[(x<<1)+1]=x;
		dfs((x<<1)+1,md+1);
	}
	if(sonsz[x]==0)
	{
		pd[md].push_back(x);
	}
	if(sonsz[x]==1)
	{
		no[md].push_back(x);
	}
	return; 
}
int main(){
	int i,j,pos,x,y,g;
	n=N;
	scanf("%d",&t);
	while(t--)
	{
		bmp=0;
		for(i=0;i<110;i++)
		{
			pd[i].clear();
			no[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			sonsz[i]=0;
		}
		scanf("%d%d",&n,&d);
		if(n*(n-1)/2<d)
		{
			puts("NO");
			continue; 
		}
		td=0;
		fa[1]=1;
		dfs(1,0);
		if(td>d)
		{
			puts("NO");
			continue;
		}
		while(td<d)
		{
			g=INF;
			for(i=1;i<110;)
			{
				if(pd[i].size()==0)
				{
					i++;
					continue;
				}
				if(pd[i].size()+no[i].size()>1)
				{
					g=1;
					x=i;
					y=i;
					break;
				}
				for(j=i+1;j<110;j++)
				{
					if(pd[j].size()!=0||no[j].size()!=0)
					{
						if(g>j-i+1)
						{
							g=j-i+1;
							x=i;
							y=j;
						}
						i=j;
						break;
					}
				}
				i=j;
			}
			if(g==INF)
			{
				td=d+100;
				break;
			}
			i=x;
			x=pd[i][pd[i].size()-1];
			sonsz[fa[x]]--;
			if(sonsz[fa[x]]==0)
			{
				pd[i-1].push_back(fa[x]);
				pos=find(no[i-1].begin(),no[i-1].end(),fa[x])-no[i-1].begin();
				no[i-1].erase(no[i-1].begin()+pos);
			}
			if(sonsz[fa[x]]==1)
			{
				no[i-1].push_back(fa[x]);
			}
			j=y;
			pd[j+1].push_back(x);
			td+=g;
			if(i!=j)
			{
				if(no[j].size()!=0)
				{
					y=no[j][no[j].size()-1];
					sonsz[y]++;
					no[j].erase(no[j].end()-1);
				}
				else
				{
					y=pd[j][pd[j].size()-1];
					sonsz[y]++;
					pd[j].erase(pd[j].end()-1);
					no[j].push_back(y);
				}
				fa[x]=y;
			}
			else
			{
				if(no[j].size()!=0)
				{
					y=no[j][no[j].size()-1];
					sonsz[y]++;
					no[j].erase(no[j].end()-1);
				}
				else
				{
					y=pd[j][pd[j].size()-2];
					sonsz[y]++;
					pd[j].erase(pd[j].end()-2);
					no[j].push_back(y);
				}
				fa[x]=y;
			}
			//cout<<x<<" "<<y<<endl;
			pd[i].erase(pd[i].end()-1);
		}
		if(td==d)
		{
			puts("YES");
			for(i=2;i<=n;i++)
			{
				printf("%d ",fa[i]);
			}
			puts("");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}