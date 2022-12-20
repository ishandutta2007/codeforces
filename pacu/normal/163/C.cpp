#include <iostream>
#include <iomanip>
using namespace std;

long long A[200001];
int N;
long long L,vBelt,vBoy;
long double prob[100001];

int main()
{
	cin >> N >> L >> vBelt >> vBoy;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		A[i+N] = A[i] + 2*L;
	}
	A[2*N] = A[N] + 2*L;
	long double dist = ((long double)(L*vBoy))/((long double)(vBelt+vBoy));
	prob[0] = 1;
	for(int i=1;i<=N;i++)
		prob[i] = 0;
	if(N==1)
	{
		cout << setprecision(20);
		cout << 1-(dist/((long double)(2*L))) << endl;
		cout << (dist/((long double)(2*L))) << endl;
		return 0;
	}
	int first = 1;
	int last = 1;
	for(;first<=N;)
	{
		long double fLow = A[first-1];
		long double fHigh = A[first];
		long double lLow = A[last]-dist;
		long double lHigh = A[last+1]-dist;
		long double low = max(fLow,lLow);
		long double high = min(fHigh,lHigh);
		prob[1+last-first] += max((long double)0,(high-low)/(2*L));
		if(lHigh < fHigh) last++;
		else first++;
		last = max(first,last);
	}
	for(int i=1;i<=N;i++)
		prob[0] -= prob[i];
	for(int i=0;i<=N;i++)
		cout << setprecision(20) << prob[i] << endl;
	return 0;
}