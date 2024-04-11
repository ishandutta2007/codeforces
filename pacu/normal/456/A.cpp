#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct laptop
{
	int price,quality;
};

bool cmp(laptop a,laptop b)
{
	if(a.price==b.price)
		return a.quality<b.quality;
	return a.price<b.price;
}

int main()
{
	int N;
	vector<laptop> A;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		A.push_back(laptop());
		cin >> A[i].price >> A[i].quality;
	}
	sort(A.begin(),A.end(),cmp);
	int best = A[0].quality;
	for(int i=1;i<N;i++)
	{
		if(A[i].price==A[i-1].price) continue;
		if(best>A[i].quality)
		{
			cout << "Happy Alex" << endl;
			return 0;
		}
		best = A[i].quality;

	}
	cout << "Poor Alex" << endl;
}