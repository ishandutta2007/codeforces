#include <iostream>;
#include <cmath>;
#include <vector>;
#include <stdio.h>;
#include <algorithm>;
#include <string>;
#include <set>;
using namespace std;
long long funk(long long n)
{
	int y;
	if(n==0)
	{
		return 0;
	}
	else
	{
		y=n%2;
		return funk(n/2)+y;
	}
}
long long  i, n, x, cur, c1, u, ans[20005], nach[10005], k, j, t;
long long an;
int main()
{
	cin>>n>>k;
	for(i=0; i<n; i++)
	{
		cin>>x;
		nach[x]++;
	}
	for(i=0; i<20004;i++)
	{
		ans[i]=funk(i);
	}
	for(i=0; i<10001; i++)
	{
		if(k==0)
		{
			an=an+(nach[i]*(nach[i]-1))/2;
		}
		else
		{
			for(j=0; j<i; j++)
			{
				t=i^j;
				if(ans[t]==k)
				{
					an=an+nach[i]*nach[j];
				//	cout<<an<<endl;
				}
			}
		}
		//cout<<i<<endl;
	}
	cout<<an;
}