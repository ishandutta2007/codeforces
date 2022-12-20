#include <iostream>
#include <iomanip>
using namespace std;

double a[100000],b[100000];
int p,q;
int N;

bool works(double x)
{
	double low = -x;
	double high = x;
	for(int i=0;i<N;i++)
	{
		if(a[i]-b[i]==0)
		{
			if(1-(a[i]+b[i])*x < 0) return 0;
		}
		else if(a[i]-b[i]>0)
		{
			high = min(high,(1-(a[i]+b[i])*x)/(a[i]-b[i]));
		}
		else
			low = max(low,(1-(a[i]+b[i])*x)/(a[i]-b[i]));
	}
	return (low <= high);
}

double binSearch(double low,double high)
{
	if(high-low < 1e-9) return low;
	double mid = (low+high)/2;
	if(works(mid)) return binSearch(mid,high);
	else return binSearch(low,mid);
}

int main()
{
	cin >> N >> p >> q;
	int c,d;
	for(int i=0;i<N;i++)
	{
		cin >> c >> d;
		a[i] = ((double)c)/((double)(2*p));
		b[i] = ((double)d)/((double)(2*q));
	}
	cout << setprecision(20) << binSearch(0,1000000) << '\n';
}