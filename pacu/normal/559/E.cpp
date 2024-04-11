#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int pt[301];
map<int,int> mIndex;

struct lamp
{
	int a,l;
};

bool cmp(lamp x,lamp y)
{
	return x.a < y.a;
}

lamp L[100];

int ans[100][301];

int getAns(int n,int iEnd)
{
//	cout << "In " << a[n] << " : " << pt[iEnd] << '\n';
	if(n == -1) return 0;
	if(ans[n][iEnd] != -1)
		//{cout << "\t" << ans[n][iEnd] << '\n'; cout << "Out " << a[n] << " : " << pt[iEnd] << '\n'; return ans[n][iEnd];}
		return ans[n][iEnd];
	int xEnd = pt[iEnd];
	if(L[n].a >= xEnd)
	{
		int xLow = xEnd;
		int j;
		for(j=n;j>=0;j--)
		{
			if(L[j].a < xEnd) break;
			xLow = min(xLow,L[j].a-L[j].l);
		}
		ans[n][iEnd] = getAns(j,mIndex[xLow])+xEnd-xLow;
	}
	else
	{
		int best = getAns(n-1,mIndex[L[n].a-L[n].l])+L[n].l;
		int xLow = xEnd;
		for(int j=n;j>=0;j--)
		{
			if(L[j].a+L[j].l > L[n].a)
				best = max(best,getAns(j-1,mIndex[min(xLow,L[j].a)])+min(L[j].a+L[j].l,xEnd)-min(xLow,L[j].a));
			xLow = min(xLow,L[j].a-L[j].l);
		}
		ans[n][iEnd] = best;
	}
//	{cout << "\t" << ans[n][iEnd] << '\n'; cout << "Out " << a[n] << " : " << pt[iEnd] << '\n'; return ans[n][iEnd];}
	return ans[n][iEnd];
}

int main()
{
	for(int i=0;i<100;i++)
		for(int j=0;j<=300;j++)
			ans[i][j] = -1;
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> L[i].a >> L[i].l;
		pt[3*i] = L[i].a;
		pt[3*i+1] = L[i].a-L[i].l;
		pt[3*i+2] = L[i].a+L[i].l;
	}
	sort(L,L+N,cmp);
	pt[3*N] = 1000000000;
	sort(pt,pt+3*N+1);
	int dif = 0;
	for(int i=1;i<=3*N;i++)
	{
		if(pt[i] == pt[i-1])
			dif++;
		else
			pt[i-dif] = pt[i];
	}
	for(int i=0;i<=3*N-dif;i++)
		mIndex[pt[i]] = i;
	cout << getAns(N-1,3*N-dif) << '\n';
}