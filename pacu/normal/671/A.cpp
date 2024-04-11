#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long long ax,ay,bx,by,tx,ty;
long long x[100000],y[100000];
double adif[100000];
double bdif[100000];
double lowal[100000];
double lowar[100000];

int main()
{
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	int N;
	cin >> N;
	double tot = 0;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> y[i];
		adif[i] = -sqrt((tx-x[i])*(tx-x[i]) + (ty-y[i])*(ty-y[i])) + sqrt((ax-x[i])*(ax-x[i]) + (ay-y[i])*(ay-y[i]));
		bdif[i] = -sqrt((tx-x[i])*(tx-x[i]) + (ty-y[i])*(ty-y[i])) + sqrt((bx-x[i])*(bx-x[i]) + (by-y[i])*(by-y[i]));
		tot += sqrt((tx-x[i])*(tx-x[i]) + (ty-y[i])*(ty-y[i]));
	}
	tot *= 2.0;
	lowal[0] = adif[0];
	for(int i=1;i<N;i++)
		lowal[i] = min(lowal[i-1],adif[i]);
	lowar[N-1] = adif[N-1];
	for(int i=N-2;i>=0;i--)
		lowar[i] = min(lowar[i+1],adif[i]);
	double best = 800000000000000.0;
	for(int i=0;i<N;i++)
	{
		double mindif = 800000000000000.0;
		if(i) mindif = min(mindif,lowal[i-1]);
		if(i<N-1) mindif = min(mindif,lowar[i+1]);
		best = min(best,tot+mindif+bdif[i]);
		best = min(best,tot+bdif[i]);
		best = min(best,tot+mindif);
	}
	if(N==1)
	{
		best = min(best,tot+adif[0]);
		best = min(best,tot+bdif[0]);
	}
	cout << setprecision(20) << best << '\n';
}