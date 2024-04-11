#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int vbuy[100001];
int vsell[100001];

int N,S;

int main()
{
	cin >> N >> S;
	char d;
	int p,q;
	for(int i=0;i<N;i++)
	{
		cin >> d >> p >> q;
		if(d == 'B')
			vbuy[p] += q;
		else
			vsell[p] += q;
	}
	vector<int> bagg;
	vector<int> sagg;
	int cur = S;
	for(int i=100000;i>=0 && cur>0;i--)
		if(vbuy[i])
			bagg.push_back(i), cur--;
	cur = S;
	for(int i=0;i<=100000 && cur>0;i++)
		if(vsell[i])
			sagg.push_back(i), cur--;
	while(sagg.size())
	{
		cout << "S " << sagg.back() << ' ' << vsell[sagg.back()] << '\n';
		sagg.pop_back();
	}
	reverse(bagg.begin(),bagg.end());
	while(bagg.size())
	{
		cout << "B " << bagg.back() << ' ' << vbuy[bagg.back()] << '\n';
		bagg.pop_back();
	}
	return 0;
}