#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int lx,ly,hx,hy;
int N;
int rx[100000],ry[100000],vx[100000],vy[100000];

void getTimes(int pos,int v,int low,int high,double &tIn,double &tOut)
{
	if(v==0)
	{
		if(pos<=low || pos>=high)
			tIn = 0.0, tOut = 0.0;
		else
			tIn = 0.0, tOut = 1000000000.0;
		return;
	}
	tIn = (low-pos)/((double)v);
	tOut = (high-pos)/((double)v);
	if(tIn>tOut) swap(tIn,tOut);
	if(tOut<0) tIn = tOut = 0.0;
	else if(tIn < 0) tIn = 0.0;
}

int main()
{
	cin >> N;
	cin >> lx >> ly >> hx >> hy;
	if(lx==hx || ly==hy)
	{
		cout << -1 << '\n';
		return 0;
	}
	double tLow = 0.0;
	double tHigh = 1000000000.0;
	for(int i=0;i<N;i++)
	{
		cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];
		double tIn,tOut;
		getTimes(rx[i],vx[i],lx,hx,tIn,tOut);
		//cout << tIn << ' ' << tOut << '\n';
		tLow = max(tLow,tIn);
		tHigh = min(tHigh,tOut);
		getTimes(ry[i],vy[i],ly,hy,tIn,tOut);
		//cout << tIn << ' ' << tOut << '\n';
		tLow = max(tLow,tIn);
		tHigh = min(tHigh,tOut);
	}
	if(tHigh-tLow < 1.0e-12)
		cout << -1 << '\n';
	else
		cout << setprecision(20) << tLow << '\n';
}