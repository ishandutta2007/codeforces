#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;


int n, m;
string slo;
long long p=37;
long long mod1=1000000007;
long long mod2=1000000009;
long long pot1[1000007];
long long pot2[1000007];
map <pair <long long,long long> ,long long> hasze[1000007];
long long h1, h2;
long long ha, hb;
int czy;

int main()
{
	cin >> n >> m;
	pot1[0]=1;
	pot2[0]=1;
	for (int i=1; i<=1000000; i++)
	{
		pot1[i]=(pot1[i-1]*p)%mod1;
		pot2[i]=(pot2[i-1]*p)%mod2;
	}
	for (int i=1; i<=n; i++)
	{
		cin >> slo;
		h1=0;
		h2=0;
		for (int i=0; i<slo.size(); i++)
		{
			h1=(h1+(slo[i]-'a'+1)*pot1[i])%mod1;
			h2=(h2+(slo[i]-'a'+1)*pot2[i])%mod2;
		}
		hasze[slo.size()][make_pair(h1, h2)]=1;
	}
	for (int i=1; i<=m; i++)
	{
		cin >> slo;
		h1=0;
		h2=0;
		for (int i=0; i<slo.size(); i++)
		{
			h1=(h1+(slo[i]-'a'+1)*pot1[i])%mod1;
			h2=(h2+(slo[i]-'a'+1)*pot2[i])%mod2;
		}
		czy=0;
		for (int i=0; i<slo.size(); i++)
		{
			if (slo[i]!='a')
			{
				ha=h1-(slo[i]-'a'+1)*pot1[i]+('a'-'a'+1)*pot1[i];
				hb=h2-(slo[i]-'a'+1)*pot2[i]+('a'-'a'+1)*pot2[i];
				ha=((ha%mod1)+mod1)%mod1;
				hb=((hb%mod2)+mod2)%mod2;
				if (hasze[slo.size()][make_pair(ha, hb)])
				{
					czy=1;
					break;
				}
			}
			if (slo[i]!='b')
			{
				ha=h1-(slo[i]-'a'+1)*pot1[i]+('b'-'a'+1)*pot1[i];
				hb=h2-(slo[i]-'a'+1)*pot2[i]+('b'-'a'+1)*pot2[i];
				ha=((ha%mod1)+mod1)%mod1;
				hb=((hb%mod2)+mod2)%mod2;
				if (hasze[slo.size()][make_pair(ha, hb)])
				{
					czy=1;
					break;
				}
			}
			if (slo[i]!='c')
			{
				ha=h1-(slo[i]-'a'+1)*pot1[i]+('c'-'a'+1)*pot1[i];
				hb=h2-(slo[i]-'a'+1)*pot2[i]+('c'-'a'+1)*pot2[i];
				ha=((ha%mod1)+mod1)%mod1;
				hb=((hb%mod2)+mod2)%mod2;
				if (hasze[slo.size()][make_pair(ha, hb)])
				{
					czy=1;
					break;
				}
			}
		}
		if (czy)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}