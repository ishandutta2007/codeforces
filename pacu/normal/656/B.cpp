#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int N;
	int m[16],r[16];
	long long l = 1;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> m[i];
	for(int i=0;i<N;i++)
		cin >> r[i];
	for(int i=0;i<N;i++)
	{
		int g = gcd(l,m[i]);
		l = (l*m[i])/g;
	}
	int cnt = 0;
	for(int i=0;i<l;i++)
	{
		bool w = 0;
		for(int k=0;k<N;k++)
			if(i%m[k] == r[k])
				w = 1;
		cnt += w;
	}
	cout << setprecision(20) << ((double)cnt)/l << '\n';
}