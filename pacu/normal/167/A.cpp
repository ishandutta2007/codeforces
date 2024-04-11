#include <iostream>
#include <iomanip>
using namespace std;

int departTime[100000];
long double mxSpeed[100000];
long double arriveTime[100000];

int main()
{
	int nBuses;
	long double acc,dist;
	cin >> nBuses >> acc >> dist;
	for(int i=0;i<nBuses;i++)
		cin >> departTime[i] >> mxSpeed[i];
	long double latest = 0;
	for(int i=0;i<nBuses;i++)
	{
		long double tAcc = mxSpeed[i]/((long double)acc);
		long double dAcc = 0.5*acc*tAcc*tAcc;
		long double time;
		if(dAcc > dist) //accelerates all the way
			time = pow(2*dist/acc,(long double)0.5);
		else			//accelerates part way
			time = tAcc + (dist-dAcc)/mxSpeed[i];
		arriveTime[i] = departTime[i] + time;
		if(arriveTime[i] < latest)
			arriveTime[i] = latest;
		else
			latest = arriveTime[i];
	}
	cout << setprecision(20);
	for(int i=0;i<nBuses;i++)
		cout << arriveTime[i] << endl;
	return 0;
}