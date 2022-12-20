#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int money;
	int i;
	vector<int> works;
	int nItems;
	int cost;
	int k;
	cin >> N >> money;
	for(i=0;i<N;i++)
	{
		vector<int> aCosts;
		cin >> nItems;
		for(int j=0;j<nItems;j++)
		{
			cin >> cost;
			aCosts.push_back(cost);
		}
		sort(aCosts.begin(),aCosts.end());
		if(aCosts[0]<money)
			works.push_back(i+1);
	}
	k = works.size();
	cout << k << endl;
	for(i=0;i<(k-1);i++)
		cout << works[i] << " ";
	if(k)
		cout << works[i] << endl;
}