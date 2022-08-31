#include <iostream>
#include <cstdio>
using namespace std;

char jak;
int n;
string alf="qwertyuiopasdfghjkl;zxcvbnm,./";
int gdzie[1000];
string slo;

int main()
{
	cin >> jak;
	n=alf.size();
	for (int i=0; i<n; i++)
	{
		gdzie[alf[i]]=i;
	}
	cin >> slo;
	for (int i=0; i<slo.size(); i++)
	{
		if (jak=='R')
		{
			cout << alf[gdzie[slo[i]]-1];
		}
		else
		{
			cout << alf[gdzie[slo[i]]+1];
		}
	}
	return 0;
}