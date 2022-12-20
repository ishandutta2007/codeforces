#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int w[1000];
int h[1000];
vector<int> qu;

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d %d",&w[i],&h[i]);
	int best = 1000000000;
	int cur;
	bool bad;
	for(int t=1;t<=1000;t++)
	{
		cur = 0;
		bad = 0;
		int leftSwap = N/2;
		int ls = 0;
		qu.clear();
		for(int i=0;i<N;i++)
		{
			if(h[i]>t)
			{
				if(w[i]>t) bad = 1;
				else if(leftSwap==0) bad = 1;
				else
				{
					cur += h[i];
					leftSwap--;
				}
			}
			else if(w[i]<=t)
			{
				cur += w[i];
				if(h[i]<w[i])
				{
					qu.push_back(h[i]-w[i]);
					ls++;
				}
			}
			else
				cur += w[i];
		}
		if(bad)
			continue;
		sort(qu.begin(),qu.end());
		for(int i=0;i<min(ls,leftSwap);i++)
			cur += qu[i];
		cur *= t;
		if(cur < best)
			best = cur;
	}
	printf("%d\n",best);
	return 0;
}