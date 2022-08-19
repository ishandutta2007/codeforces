#include <iostream>
#include <cstdio>
using namespace std;

int n, p;
string slo;
char cionk[1007];
char dow;
char wyn[1007];
int od;
bool out;

int main()
{
	scanf("%d%d", &n, &p);
	cin >> slo;
	for (int i=2; i<=n+1; i++)
	{
		cionk[i]=slo[i-2]-'a'+1;
	}
	for (int i=n+1; i>1; i--)
	{
		for (char j=cionk[i]+1; j<=p; j++)
		{
			if (j!=cionk[i-1] && j!=cionk[i-2])
			{
				od=i;
				for (int k=2; k<=n+1; k++)
				{
					if (k==i)
					wyn[k]=j;
					if (k<i)
					wyn[k]=cionk[k];
				}
				out=true;
			}
			if (out)
			break;
		}
		if (out)
		break;
	}
	if (!od)
	{
		cout << "NO";
		return 0;
	}
	for (int i=od+1; i<=n+1; i++)
	{
		for (char j=1; j<=p; j++)
		{
			if (j!=wyn[i-1] && j!=wyn[i-2])
			{
				wyn[i]=j;
				break;
			}
		}
	}
	for (int i=2; i<=n+1; i++)
	{
		dow=wyn[i]+'a'-1;
		cout << dow;
	}
	return 0;
}