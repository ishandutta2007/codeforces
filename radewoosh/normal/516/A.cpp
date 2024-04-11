#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string slo;
vector <int> roz[15];
int a;

int ile[15];

void pacz(int v)
{
	for (int i=2; i<=v; i++)
	{
		if (!(v%i))
		{
			ile[i]++;
			v/=i;
			i--;
		}
	}
}

int main()
{
	roz[2].push_back(2);
	
	roz[3].push_back(3);
	roz[3].push_back(2);
	
	roz[5].push_back(5);
	roz[5].push_back(2);
	roz[5].push_back(2);
	roz[5].push_back(3);
	roz[5].push_back(2);
	
	roz[7].push_back(7);
	roz[7].push_back(3);
	roz[7].push_back(2);
	roz[7].push_back(5);
	roz[7].push_back(2);
	roz[7].push_back(2);
	roz[7].push_back(3);
	roz[7].push_back(2);
	
	cin >> n;
	cin >> slo;
	for (int i=0; i<n; i++)
	for (int j=2; j<=slo[i]-'0'; j++)
	pacz(j);
	for (int i=10; i>1; i--)
	{
		a=ile[i];
		for (int j=1; j<=a; j++)
		{
			printf("%d", i);
		}
		for (int j=0; j<roz[i].size(); j++)
		{
			ile[roz[i][j]]-=a;
		}
	}
	return 0;
}