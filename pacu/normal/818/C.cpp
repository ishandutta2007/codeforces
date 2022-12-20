#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005

int D,N,M;
int x1[MAXN],x2[MAXN],y1[MAXN],y2[MAXN];
int lowx[MAXN],lowy[MAXN],highx[MAXN],highy[MAXN];
int cntl[MAXN],cntr[MAXN],cntt[MAXN],cntb[MAXN];

int main()
{
	cin >> D >> N >> M;
	for(int i=0;i<D;i++)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		if(x1[i]>x2[i]) swap(x1[i],x2[i]);
		if(y1[i]>y2[i]) swap(y1[i],y2[i]);
		lowx[x1[i]]++, highx[x2[i]]++;
		lowy[y1[i]]++, highy[y2[i]]++;
	}
	for(int i=1;i<=N;i++)
		lowx[i] += lowx[i-1];
	for(int i=N;i>=1;i--)
		highx[i] += highx[i+1];
	for(int i=1;i<=M;i++)
		lowy[i] += lowy[i-1];
	for(int i=M;i>=1;i--)
		highy[i] += highy[i+1];
	int q1,q2,q3,q4;
	cin >> q1 >> q2 >> q3 >> q4;
	for(int i=0;i<D;i++)
	{
		if(q1==lowx[x2[i]-1]-(x1[i]<x2[i]) && q2==highx[x1[i]+1]-(x1[i]<x2[i]) && q3==lowy[y2[i]-1]-(y1[i]<y2[i]) && q4==highy[y1[i]+1]-(y1[i]<y2[i]))
		{
			cout << i+1 << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}