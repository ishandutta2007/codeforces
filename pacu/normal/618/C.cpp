#include <iostream>
#include <cmath>
using namespace std;

int N;
long long x[100000],y[100000];

long long area(int i,int j,int k)
{
	long long vx = x[j]-x[i];
	long long vy = y[j]-y[i];
	long long wx = x[k]-x[i];
	long long wy = y[k]-y[i];
	return abs(vx*wy-vy*wx);
}

long long dist(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> x[i] >> y[i];
	int p1 = 1;
	for(int i=2;i<N;i++)
		if(dist(0,i) < dist(0,p1))
			p1 = i;
	int low = 1;
	long long langle = -1;
	long long cangle;
	for(int i=1;i<N;i++)
	{
		cangle = area(0,p1,i);
		if((langle==-1 || cangle<langle) && cangle>0)
		{
			langle = cangle;
			low = i;
		}
	}
	cout << 1 << ' ' << p1+1 << ' ' << low+1 << '\n';
}