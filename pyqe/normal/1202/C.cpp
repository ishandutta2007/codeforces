#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,yk[26],a[200069],ps[2][200069],bo[2][2];
deque<pair<long long,long long>> dq[2][2];

int main()
{
	long long t,rr,i,ii,iii,u,im,mv[2][4]={{-1,0,1,0},{0,1,0,-1}},z;
	string s;
	
	yk[22]=0;
	yk[3]=1;
	yk[18]=2;
	yk[0]=3;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=yk[s[i-1]-'A'];
			for(ii=0;ii<2;ii++)
			{
				ps[ii][i]=ps[ii][i-1]+mv[ii][a[i]];
			}
		}
		z=1e18;
		for(im=0;im<4;im++)
		{
			for(i=n+1;i;i--)
			{
				for(ii=0;ii<2;ii++)
				{
					ps[ii][i]=ps[ii][i-1]+mv[ii][im];
				}
			}
			for(i=0;i<=n+1;i++)
			{
				for(ii=0;ii<2;ii++)
				{
					for(iii=0;iii<2;iii++)
					{
						u=!iii*2-1;
						for(;!dq[ii][iii].empty()&&dq[ii][iii].back().fr*u<=ps[ii][i]*u;dq[ii][iii].pop_back());
						dq[ii][iii].push_back({ps[ii][i],i});
					}
				}
			}
			for(i=0;i<=n;i++)
			{
				for(ii=0;ii<2;ii++)
				{
					ps[ii][i]=ps[ii][i+1]-mv[ii][im];
					for(iii=0;iii<2;iii++)
					{
						u=!iii*2-1;
						for(;!dq[ii][iii].empty()&&dq[ii][iii].back().fr*u<=ps[ii][i]*u;dq[ii][iii].pop_back());
						dq[ii][iii].push_back({ps[ii][i],n+1+i});
						for(;dq[ii][iii].front().sc<=i;dq[ii][iii].pop_front());
						bo[ii][iii]=dq[ii][iii].front().fr;
					}
				}
				z=min(z,(bo[0][0]-bo[0][1]+1)*(bo[1][0]-bo[1][1]+1));
			}
			for(ii=0;ii<2;ii++)
			{
				for(iii=0;iii<2;iii++)
				{
					for(;!dq[ii][iii].empty();dq[ii][iii].pop_front());
				}
			}
		}
		printf("%lld\n",z);
	}
}