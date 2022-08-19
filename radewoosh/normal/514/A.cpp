#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string slo;
int a;

int main()
{
	cin >> slo;
	for (int i=0; i<slo.size(); i++)
	{
		a=slo[i]-'0';
		a=min(a, 9-a);
		if (a==0 && !i)
		a=9;
		printf("%d", a);
	}
	return 0;
}