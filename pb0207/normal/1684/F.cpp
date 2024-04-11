#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,m;

int a[N];

map<int,vector<int> >pos;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>v;

int to[N],r[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		pos.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),pos[a[i]].push_back(i),r[i]=0;
		v.clear();
		for(int i=1;i<=m;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			v.push_back({l,r});
		}
		sort(v.begin(),v.end());
		auto it=v.begin();
		int rp=0;
		int R=0;
		for(int i=1;i<=n;i++)
		{
			while(it!=v.end()&&it->fs<=i)
				rp=max(rp,it->sd),it++;
			auto ip=upper_bound(pos[a[i]].begin(),pos[a[i]].end(),rp);
			if(ip==pos[a[i]].begin())
				continue;
			ip--;
			if(*ip<=i)
				continue;
			R=max(R,i);
			r[i+1]=max(r[i+1],*ip);
			r[*ip+1]=1e9;
		}
		sort(v.begin(),v.end(),[&](const pii &a,const pii &b){return a.sd>b.sd;});
		it=v.begin();
		int lp=n+1;
		for(int i=n;i>=1;i--)
		{
			while(it!=v.end()&&it->sd>=i)
				lp=min(lp,it->fs),it++;
			auto ip=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),lp);
			if(ip==pos[a[i]].end())
				continue;
			if(*ip>=i)
				continue;
			R=max(R,*ip);
			r[*ip+1]=max(r[*ip+1],i);
			r[i+1]=1e9;
		}
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			R=max(R,r[i]);
			ans=min(ans,R-i+1);
		}
		ans=max(ans,0);
		printf("%d\n",ans);
	}
}