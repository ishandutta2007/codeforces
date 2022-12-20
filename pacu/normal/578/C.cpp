#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct line
{
	int m,b;
};

bool cmp(line a,line b)
{
	return a.m > b.m;
};

line L[200001];
int A[200001];
int s[200001];

double inter(int i,int j)
{
	return (L[j].b-L[i].b)/((double)(L[i].m-L[j].m));
}

double evl(int i,double x)
{
	return L[i].m*x + L[i].b;
}

int sMin[200001],sMax[200001];

int main()
{
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> A[i];
	s[0] = 0;
	for(int i=1;i<=N;i++)
		s[i] = s[i-1] + A[i];
	for(int i=0;i<=N;i++)
	{
		L[i].m = -i;
		L[i].b = s[i];
	}
	sort(L,L+N+1,cmp);
	int sz = 0;
	sMin[sz++] = 0;
	for(int i=1;i<=N;i++)
	{
		while(sz >= 2 && inter(sMin[sz-1],sMin[sz-2]) >= inter(sMin[sz-1],i))
			sz--;
		sMin[sz++] = i;
	}
//	for(int i=0;i<sz;i++)
//		cout << L[sMin[i]].b << ' ';
//	cout << '\n';
	int SZ = 0;
	sMax[SZ++] = N;
	for(int i=N-1;i>=0;i--)
	{
		while(SZ >= 2 && inter(sMax[SZ-1],sMax[SZ-2]) >= inter(sMax[SZ-1],i))
			SZ--;
		sMax[SZ++] = i;
	}
//	for(int i=0;i<SZ;i++)
//		cout << L[sMax[i]].b << ' ';
//	cout << '\n';
//	cout << setprecision(20) << fixed;
	double ans = 2000000001;
	int ti = 0;
	double xl;
	for(int i=0;i<sz-1;i++)
	{
		xl = inter(sMin[i],sMin[i+1]);
		while(ti < SZ-1 && inter(sMax[ti],sMax[ti+1]) <= xl)
			ti++;
		ans = min(ans,evl(sMax[ti],xl)-evl(sMin[i],xl));
//		cout << xl << ": " << L[sMax[ti]].b << ' ' << L[sMin[i]].b << '\n';
	}
	ti = 0;
	for(int i=0;i<SZ-1;i++)
	{
		xl = inter(sMax[i],sMax[i+1]);
		while(ti < sz-1 && inter(sMin[ti],sMin[ti+1]) <= xl)
			ti++;
		ans = min(ans,evl(sMax[i],xl)-evl(sMin[ti],xl));
	}
	cout << setprecision(20) << fixed << ans << '\n';
}