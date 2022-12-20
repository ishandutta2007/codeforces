#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define ll long long

long long pw(int k)
{
	return 1LL<<((long long)k);
}

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

double prob[200];

int x[100000],y[100000];
int N;

double getCross(ll x1, ll y1, ll x2, ll y2)
{
	return x1*y2 - x2*y1;
}

double getArea(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	return fabs(getCross(x2-x1,y2-y1,x3-x1,y3-y1))/2.0;
}

long long linelats(int i,int j)
{
	return fabs(gcd(x[i]-x[j%N],y[i]-y[j%N]));
}

int aLats[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> x[i] >> y[i];
	if(N <= 61)
		prob[2] = ((double)(pw(N-2)-1LL))/((double)(pw(N)-(N*N+N+2)/2));
	else
		prob[2] = 1.0/4.0;
	double dif;
	for(int i=3;i<N && i<100;i++)
	{
		if(N-i <= 61) dif = (1.0/((double)(pw(N-i)-1)));
		else dif = 0;
		prob[i] = prob[i-1]/(2.0+dif);
	}
	double tArea = 0;
	for(int i=1;i<=N-2;i++)
		tArea += getArea(x[0],y[0],x[i],y[i],x[i+1],y[i+1]);
	long long bLats = 0;
	for(int i=0;i<N;i++)
	{
		aLats[i] = linelats(i,i+1);
		bLats += aLats[i];
	}
	double inLats = tArea - (((double)bLats)/2.0) + 1;
	for(int i=0;i<N;i++)
	{
		long double area = 0;
		long long cbLats = aLats[i];
		long long cinLats = 0;
		long long tmp;
		int k = (i+1)%N;
		for(int j=2;j<N && j<64;j++,k=(k+1)%N)
		{
			if(j>2)
			{
				tmp = linelats(i,k);
				cinLats = area - ((double)(cbLats+tmp)/2.0) + 1;
				inLats -= prob[j]*(cinLats + tmp-1);
			}
//			cout << i << ' ' << k << ": " << prob[j] << ' ' << cinLats << ' ' << linelats(i,k)-1 << '\n';
			
			area += getArea(x[i],y[i],x[k],y[k],x[(k+1)%N],y[(k+1)%N]);
			cbLats += aLats[k];
		}
	}
	cout << setprecision(20) << fixed << inLats << '\n';
}