#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int tab[307];
vector <int> ost;
vector <int> now;
int x;
int czy;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	ost.push_back(0);
	for (int i=1; i<=n; i++)
	{
		now.clear();
		for (int j=ost.size(); j>=0; j--)
		{
			now.push_back(0);
		}
		for (int j=ost.size()-1; j>=0; j--)
		{
			/*if (tab[i]<=ost[j] && !tab[i])
			{
				now.clear();
				for (int l=ost.size(); l>=0; l--)
				{
					now.push_back(0);
				}
				now[now.size()-1]++;
				tab[i]--;
				break;
			}*/
			if (tab[i]<=ost[j])
			{
				for (int l=j+1; 1; l++)
				{
					if (now[l]<9 && tab[i])
					{
						now[l]++;
						tab[i]--;
						break;
					}
					else
					{
						tab[i]+=now[l];
						now[l]=0;
					}
				}
				break;
			}
			now[j]=ost[j];
			tab[i]-=ost[j];
		}
		for (int j=0; 1; j++)
		{
			if (!tab[i])
			break;
			if (j==now.size())
			now.push_back(0);
			x=min(tab[i], 9-now[j]);
			now[j]+=x;
			tab[i]-=x;
		}
		czy=0;
		if (now.size()==ost.size())
		{
			for (int j=ost.size()-1; j>=0; j--)
			{
				if (now[j]>ost[j])
				{
					czy=1;
					break;
				}
				if (now[j]<ost[j])
				{
					now[j]=tab[i];
					tab[i]=0;
					break;
				}
			}
		}
		if (!czy)
		{
			
		}
		while(!now.back())
		now.pop_back();
		/*rob(tab[i]);
		while(!czyw())
		{
			now.push_back(1);
			now[now.size()-2]--;
		}*/
		for (int j=now.size()-1; j>=0; j--)
		printf("%d", now[j]);
		printf("\n");
		ost=now;
	}
	return 0;
}