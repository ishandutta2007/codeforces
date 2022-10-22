#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>o[3],p[3];

ll n,t[300010],ddd[300010],lst=0;

char s[3];

ll res;

int main() 
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&ddd[i]);scanf("%s",s+1);
		if(s[1]=='B')
			t[i]=1;
		if(s[1]=='P')
			t[i]=2;
		o[t[i]].push_back(ddd[i]);
	}
	if(!o[2].size()) 
	{
		printf("%lld\n",(o[1].size()?o[1].back()-o[1][0]:0)+(o[0].size()?o[0].back()-o[0][0]:0));
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(t[i]==2) 
		{
			for(int j=lst+1;j<i;j++)
				p[t[j]].push_back(ddd[j]);
			if(!lst) 
			{
				for(int tp=1;~tp;tp--)
					if(p[tp].size())
						res+=ddd[i]-p[tp][0];
				lst=i;
			}
			else 
			{
				ll ret=0;
				for(int tp=1,d;~tp;tp--) 
				{
					d=0;
					for(int j=1;j<p[tp].size();j++)
						d=max(d,p[tp][j]-p[tp][j-1]);
					if(p[tp].size())
						ret+=ddd[i]-ddd[lst]-max(1ll*d,max(p[tp][0]-ddd[lst],ddd[i]-p[tp].back()));
				}
				res+=min(ret,ddd[i]-ddd[lst])+ddd[i]-ddd[lst];
				lst=i;
			}
			for(int j=1;~j;j--)
				p[j].clear();
		}
	for(int i=lst+1;i<=n;i++)
		p[t[i]].push_back(ddd[i]);
	for(int tp=1;~tp;tp--)
		if(p[tp].size())
			res+=p[tp].back()-ddd[lst];
	printf("%lld\n",res);
}