#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector <int> graf[1000007];
int czar[1000007];
unsigned long long wync[1000007];
unsigned long long wynb[1000007];
unsigned long long mod=1000000007;
int p;
unsigned long long tabp[1000007];
unsigned long long tabs[1000007];

int main()
{
	scanf("%d", &n);
	for (int i=2; i<=n; i++)
	{
		scanf("%d", &p);
		graf[p+1].push_back(i);
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &czar[i]);
	}
	for (int i=n; i; i--)
	{
		if (czar[i])
		{
			wync[i]=1;
			for (int j=0; j<graf[i].size(); j++)
			{
				wync[i]*=(wync[graf[i][j]]+wynb[graf[i][j]])%mod;
				wync[i]=wync[i]%mod;
			}
		}
		else
		{
			wynb[i]=1;
			tabp[0]=1;
			tabs[graf[i].size()+1]=1;
			for (int j=0; j<graf[i].size(); j++)
			{
				wynb[i]*=(wynb[graf[i][j]]+wync[graf[i][j]])%mod;
				wynb[i]=wynb[i]%mod;
			}
			for (int j=0; j<graf[i].size(); j++)
			{
				tabp[j+1]=tabp[j]*((wynb[graf[i][j]]+wync[graf[i][j]])%mod);
				tabp[j+1]=tabp[j+1]%mod;
			}
			for (int j=graf[i].size()-1; j>=0; j--)
			{
				tabs[j+1]=tabs[j+2]*((wynb[graf[i][j]]+wync[graf[i][j]])%mod);
				tabs[j+1]=tabs[j+1]%mod;
			}
			for (int j=0; j<graf[i].size(); j++)
			{
				wync[i]+=(((tabp[j]*tabs[j+2])%mod)*wync[graf[i][j]])%mod;
				wync[i]=wync[i]%mod;
			}
		}
	}
	printf("%llu", wync[1]);
	return 0;
}