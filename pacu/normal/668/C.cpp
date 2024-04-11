#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double mx[100000],mn[100000];
int N;
double a[100000],b[100000];
int flip[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	for(int i=0;i<N;i++) cin >> mx[i];
	for(int i=0;i<N;i++) cin >> mn[i];
	for(int i=1;i<N;i++) mx[i] += mx[i-1];
	for(int i=N-2;i>=0;i--) mn[i] += mn[i+1];
	for(int i=0;i<N-1;i++)
	{
		double p = mx[i];
		double s = 1 - mn[i+1] + p;
		double disc = sqrt(max(0.0,s*s-4*p));
		a[i] = (s - disc)/(2.0);
		b[i] = (s + disc)/(2.0);
	}
	a[N-1] = b[N-1] = 1.0;
	for(int i=1;i<N;i++)
	{
		if(a[i] < a[i-1]-1.0e-10 || b[i] < b[i-1]-1.0e-10)
			flip[i-1] = 1;
	}
	int cur = 0;
	for(int i=N-2;i>=0;i--)
	{
		cur += flip[i];
		if(cur%2) swap(a[i],b[i]);
	}
	for(int i=N-1;i>0;i--)
	{
		a[i] -= a[i-1];
		b[i] -= b[i-1];
	}
	cout << setprecision(20) << '\n';
	for(int i=0;i<N;i++)
	{
		if(a[i]<0) a[i] = 0;
		cout << a[i] << ' ';
	}
	cout << '\n';
	for(int i=0;i<N;i++)
	{
		if(b[i]<0) b[i] = 0;
		cout << b[i] << ' ';
	}
	cout << '\n';
}