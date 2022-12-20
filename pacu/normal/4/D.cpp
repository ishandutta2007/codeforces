#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rect
{
	int w,h;
	int id;
};

bool cmp(Rect a,Rect b)
{
	if(a.w==b.w)
		return a.h<b.h;
	return a.w<b.w;
}

bool fits(Rect outer,Rect inner)
{
	return ((outer.w>inner.w)&&(outer.h>inner.h));
}

int dp[5000];	//max length dp ending in i'th envelope
int previ[5000];

int main()
{
	int N;
	Rect card;
	vector<Rect> A;
	int i,j;
	cin >> N >> card.w >> card.h;
	for(i=0;i<N;i++)
	{
		A.push_back(Rect());
		cin >> A[i].w >> A[i].h;
		A[i].id = i+1;
	}
	sort(A.begin(),A.end(),cmp);
	for(i=0;i<N;i++)
	{
		if(!fits(A[i],card))
			dp[i] = -1;
		else
		{
			dp[i] = 1;
			previ[i] = -1;
			for(j=0;j<i;j++)
				if(fits(A[i],A[j]))
				{
					if(dp[i] < (dp[j]+1))
					{
						dp[i] = max(dp[i],dp[j]+1);
						previ[i] = j;
					}
				}
		}
	}
	int best = -1;
	int iBest = -1;
	for(i=0;i<N;i++)
	{
		if(best < dp[i])
		{
			best = dp[i];
			iBest = i;
		}
	}
	if(best==-1)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << best << endl;
	vector<int> ans;
	while(iBest!=-1)
	{
		ans.push_back(A[iBest].id);
		iBest = previ[iBest];
	}
	for(i=(ans.size()-1);i>=0;i--)
		cout << ans[i] << " ";
}