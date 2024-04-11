#include <bits/stdc++.h>
using namespace std;

int mod=1000000007;

int n;

long long mam[1000007];
long long wzro[1000007];

long long iletu[1000007];
long long roz[1000007];

char wcz[1000007];
vector <long long> liczba;
vector <long long> liczba2;

vector <int> dp[1000007];

int main()
{
	scanf("%d", &n);
	wzro[0]=wzro[1]=1;
	for (int i=2; i<=n; i++)
		scanf("%lld", &wzro[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &mam[i]);
		
	scanf("%s", wcz+1);
	for (int i=1; wcz[i]; i++)
		liczba2.push_back(wcz[i]-'0');
	reverse(liczba2.begin(), liczba2.end());
	while(liczba2.size()%3)
		liczba2.push_back(0);
	for (int i=0; i<liczba2.size(); i+=3)
		liczba.push_back(liczba2[i]+10*liczba2[i+1]+100*liczba2[i+2]);
	
	for (int i=1; i<n; i++)
	{
		if (wzro[i+1]==1)
			continue;
		long long resz=0;
		for (int j=(int)liczba.size()-1; j>=0; j--)
		{
			resz=liczba[j]%wzro[i+1];
			liczba[j]/=wzro[i+1];
			if (j)
				liczba[j-1]+=resz*1000;
		}
		while(!liczba.empty() && !liczba.back())
			liczba.pop_back();
		iletu[i]=resz;
	}
	if (liczba.size()>2)
	{
		printf("0\n");
		return 0;
	}
	for (int i=(int)liczba.size()-1; i>=0; i--)
		iletu[n]=(iletu[n]*1000+liczba[i]);
	for (int i=1; i<=n; i++)
		roz[i]=mam[i]+roz[i-1]/wzro[i];
	roz[0]=1;
	for (int i=0; i<=n; i++)
	{
		dp[i].resize(roz[i]+2, 0);
	}
	if (iletu[n]>roz[n])
	{
		printf("0\n");
		return 0;
	}
	dp[n][iletu[n]]=1;
	for (int i=n; i; i--)
	{
		int s=0;
		for (int j=roz[i]; j>=0; j--)
		{
			s+=dp[i][j];
			if (s>=mod)
				s-=mod;
			if (j+mam[i]+1<=roz[i])
			{
				s+=mod-dp[i][j+mam[i]+1];
				if (s>=mod)
					s-=mod;
			}
			long long cel=j*wzro[i]+iletu[i-1];
			if (cel<=roz[i-1])
				dp[i-1][cel]=s;
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}