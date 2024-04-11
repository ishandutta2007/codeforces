#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	unsigned long long a,b;
	vector<int> pa,pb;
	int i,j;
	unsigned long long sa,sb;
	cin >> a >> b;
	for(i=0,sa=0;i<a;i++)
	{
		pa.push_back(0);
		cin >> pa[i];
		sa += pa[i];
	}
	for(i=0,sb=0;i<b;i++)
	{
		pb.push_back(0);
		cin >> pb[i];
		sb += pb[i];
	}
	sort(pa.begin(),pa.end(),cmp);
	sort(pb.begin(),pb.end(),cmp);
	unsigned long long ans = 0;
	unsigned long long ahubtot = 0;
	unsigned long long cur;
	for(int ahub=1;ahub<=a;ahub++)
	{
		ahubtot += pa[ahub-1];
		cur = sb*ahub + (sa-ahubtot);
		if((ans>cur)||(ans==0))
			ans = cur;
	}
	unsigned long long bhubtot = 0;
	for(int bhub=1;bhub<=b;bhub++)
	{
		bhubtot += pb[bhub-1];
		cur = sa*bhub + (sb-bhubtot);
		if((ans>cur)||(ans==0))
			ans = cur;
	}
	cout << ans << endl;
}