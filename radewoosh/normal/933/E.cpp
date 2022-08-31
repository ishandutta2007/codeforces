#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int nax=300*1007;

int n;
ll tab[nax];
ll dp[nax];

vector <int> wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=n-1; i; i--)
		dp[i]=min(dp[i+2]+tab[i+1], dp[i+3]+max(tab[i+1], tab[i+2]));
	int czy=1;
	if (dp[2]+tab[1]<dp[1])
		czy++;
	if (czy==2)
		wyn.push_back(1);
	for (int i=czy; i<n;)
	{
		if (dp[i+2]+tab[i+1]<dp[i+3]+max(tab[i+1], tab[i+2]))
		{
		    wyn.push_back(i+1);
		    wyn.push_back(i);
			i+=2;
		}
		else
		{
		    wyn.push_back(i+1);
		    wyn.push_back(i+2);
		    wyn.push_back(i);
			i+=3;
		}
	}
	auto pom=wyn;
	wyn.clear();
	for (int i : pom)
	{
		if (i<n && tab[i] && tab[i+1])
		{
			ll x=min(tab[i], tab[i+1]);
			tab[i]-=x;
			tab[i+1]-=x;
			wyn.push_back(i);
		}
	}
	printf("%d\n", (int)wyn.size());
	for (int i : wyn)
		printf("%d\n", i);
	return 0;
}