#include <iostream>
#include <cstdio>
using namespace std;
#define SEG (1<<17)
#define INF 10000000000000000LL

long long height[100002];
long long dist[100002];

long long segMinus[2*SEG];
long long segPlus[2*SEG];
long long segBoth[2*SEG];
int l[2*SEG];
int r[2*SEG];
int N,M;

void initBounds()
{
	for(int i=SEG;i<2*SEG;i++)
		l[i] = r[i] = i-SEG;
	for(int i=SEG-1;i>0;i--)
	{
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		if((i-SEG)>=N) segMinus[i] = segPlus[i] = segBoth[i] = -INF;
		else
		{
			segMinus[i] = 2*height[i-SEG] - dist[i-SEG];
			segPlus[i] = 2*height[i-SEG] + dist[i-SEG];
			segBoth[i] = -INF;
		}
	}
	for(int i=SEG-1;i>0;i--)
	{
		segMinus[i] = max(segMinus[2*i],segMinus[2*i+1]);
		segPlus[i] = max(segPlus[2*i],segPlus[2*i+1]);
		segBoth[i] = max(max(segBoth[2*i],segBoth[2*i+1]),segMinus[2*i]+segPlus[2*i+1]);
	}
}

void segGet(int i,int low,int high,long long &m,long long &p,long long &b)
{
	if((r[i]<low)||(l[i]>high))
	{
		m = p = b = -INF;
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		m = segMinus[i];
		p = segPlus[i];
		b = segBoth[i];
		return;
	}
	long long m1,p1,b1,m2,p2,b2;
	segGet(2*i,low,high,m1,p1,b1);
	segGet(2*i+1,low,high,m2,p2,b2);
	m = max(m1,m2);
	p = max(p1,p2);
	b = max(max(b1,b2),m1+p2);
//	cout << i << ": " << m << " " << p << " " << b << endl;
}

int main()
{
	cin >> N >> M;
	long long dCircle;
	dist[0] = 0;
	for(int i=1;i<N;i++)
	{
		cin >> dist[i];
		dist[i] += dist[i-1];
	}
	cin >> dCircle;
	long long total = dist[N-1] + dCircle;
	for(int i=0;i<N;i++)
		cin >> height[i];
	initBounds();
	init();
	int a,b;
	long long m1,p1,b1,m2,p2,b2;
//	cout << segBoth[1] << endl;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		if(a > b)
		{
			a--,b++;
			segGet(1,b,a,m1,p1,b1);
			cout << b1 << endl;
		}
		else
		{
			a--,b++;
			long long best = -INF;
			if(a>=0)
			{
				segGet(1,0,a,m1,p1,b1);
				best = max(best,b1);
			}
			if(b<N)
			{
				segGet(1,b,N-1,m2,p2,b2);
				best = max(best,b2);
			}
			if((a>=0)&&(b<N))
				best = max(best,m2+p1+total);
			cout << best << endl;
		}
	}
	return 0;
}