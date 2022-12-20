#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int discounts,prices;
	int aTypes[100000];
	int aPrices[100000];
	cin >> discounts;
	for(int i=0;i<discounts;i++)
		cin >> aTypes[i];
	cin >> prices;
	for(int j=0;j<prices;j++)
		cin >> aPrices[j];
	sort(aTypes,aTypes+discounts);
	sort(aPrices,aPrices+prices);
	long long cost = 0;
	int j = prices-1;
	while(j >= 0)
	{
		for(int i=0;i<aTypes[0];i++)
		{
			cost += aPrices[j];
			j--;
			if(j<0)
				break;
		}
		j = j-2;
	}
	cout << cost << endl;
}