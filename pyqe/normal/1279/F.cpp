#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,d,ps[1000069],dp[1000069],op[1000069];
bitset<1000069> a;
deque<pair<pair<int,int>,int>> dq;

int main()
{
	int i,ii,k,w,lh,rh,md,mx,e,zz,zx,mn=1e9;
	pair<int,int> mxe,tmp;
	char s[1000069];
	
	scanf("%d%d%d%s",&n,&m,&d,s);
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]>='A'&&s[i-1]<='Z';
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1]+(a[i]^ii);
		}
		zz=0;
		zx=ps[n];
		for(lh=1,rh=d;lh<=rh;)
		{
			md=(lh+rh)/2;
			mxe={-1e9,-1e9};
			dp[0]=0;
			op[0]=0;
			for(i=1;i<=n+d;i++)
			{
				if(i>=d)
				{
					mxe=max(mxe,{dp[i-d],op[i-d]});
				}
				mx=mxe.fr;
				e=mxe.sc;
				if(i<=n)
				{
					for(;!dq.empty()&&dq.front().sc<=i-d;dq.pop_front());
					if(!dq.empty())
					{
						k=dq.front().fr.sc;
						w=dq.front().fr.fr;
					}
					else
					{
						k=-1e9;
						w=-1e9;
					}
					tmp=max(mp(ps[i]+w-md,k+1),mp(ps[i]-ps[i-d]+mx-md,e+1));
					dp[i]=tmp.fr;
					op[i]=tmp.sc;
					for(;!dq.empty()&&dq.back().fr<=mp(dp[i]-ps[i],op[i]);dq.pop_back());
					dq.push_back({{dp[i]-ps[i],op[i]},i});
				}
			}
			for(;!dq.empty();dq.pop_front());
			if(e>=m)
			{
				zz=md;
				zx=mx;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		mn=min(mn,ps[n]-zx-zz*m);
	}
	printf("%d\n",mn);
}