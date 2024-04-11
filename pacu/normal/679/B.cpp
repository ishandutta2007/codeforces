#include <iostream>
using namespace std;

long long m;

int mx[30000000];
int ps[30000000];

int bestNum;
long long bestX;

void test(long long a1)
{
	if(1 > bestNum || (1 == bestNum && a1*a1*a1 > bestX))
		bestNum = 1, bestX = a1*a1*a1;
	long long spare = min(3*a1*a1 + 3*a1,m-a1*a1*a1);
	for(long long a2=1;a2<=3110 && a2*a2*a2 <= spare;a2++)
	{
		long long maxleft = min(3*a2*a2+3*a2,spare-a2*a2*a2);
		if(mx[ps[maxleft]]+2 > bestNum || (mx[ps[maxleft]]+2 == bestNum && a1*a1*a1+a2*a2*a2+ps[maxleft] > bestX))
			bestNum = mx[ps[maxleft]]+2, bestX = a1*a1*a1+a2*a2*a2+ps[maxleft];
	}	
}

int main()
{
	cin >> m;
	mx[0] = 0;
	ps[0] = 0;
	int lg = 1;
	for(int i=1;i<30000000;i++)
	{
		if((lg+1)*(lg+1)*(lg+1) == i) lg++;
		mx[i] = 1 + mx[i-lg*lg*lg];
		if(mx[i] >= mx[ps[i-1]])
			ps[i] = i;
		else
			ps[i] = ps[i-1];
	}
	long long a1 = 1;
	while((a1+1)*(a1+1)*(a1+1) <= m) a1++;
	test(a1-1);
	test(a1);
	cout << bestNum << ' ' << bestX << '\n';
}