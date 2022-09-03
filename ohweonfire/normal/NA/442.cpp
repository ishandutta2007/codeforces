#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=1111;
int n,k,ax[maxn],ay[maxn],mx[maxn],my[maxn];

vector<int> block[maxn][7];

bool done[maxn];
bool check(int msk,const vector<int>&vs)
{
	if((int)vs.size()==0)return true;
	if(msk==0)return false;
	for(int i=0;i<(int)vs.size();i++)
	{
		int x=vs[i];
		for(int j=0;j<k;j++)if((msk>>j)&1)
		{
			if((int)block[x][j].size()>=__builtin_popcount(msk))continue;
			vector<int> nv;for(int t=0;t<(int)vs.size();t++)if(t!=i)nv.pb(vs[t]);
			bool ok=1;
			for(int t=0;t<(int)block[x][j].size();t++)
			{
				if(done[block[x][j][t]])
				{
					ok=0;
					break;
				}
				nv.pb(block[x][j][t]);
			}
			if(!ok)continue;
			sort(nv.begin(),nv.end());nv.erase(unique(nv.begin(),nv.end()),nv.end());
			if((int)nv.size()>=__builtin_popcount(msk))continue;
			done[x]=1;
			if(check(msk^(1<<j),nv))return true;
			done[x]=0;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&k,&n);
	for(int i=0;i<k;i++)scanf("%d%d",ax+i,ay+i);
	for(int i=0;i<n;i++)scanf("%d%d",mx+i,my+i);
	
	for(int i=0;i<n;i++)for(int t=0;t<k;t++)
	{
		for(int j=0;j<n;j++)if(j!=i)
		{
			LL det=(LL)(mx[i]-ax[t])*(my[j]-ay[t])-(LL)(mx[j]-ax[t])*(my[i]-ay[t]);
			if(det==0&&(LL)(mx[j]-ax[t])*(mx[j]-mx[i])<=0&&(LL)(my[j]-ay[t])*(my[j]-my[i])<=0)
			{
				block[i][t].pb(j);
//				printf("block %d %d %d\n",i,t,j);
			}
		}
	}
	
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		vector<int> vs;vs.pb(i);
		memset(done,0,sizeof(done));
		if(check((1<<k)-1,vs))cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}