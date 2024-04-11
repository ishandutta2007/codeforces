#include <iostream>
#include <map>
using namespace std;

map<long long,int> occ;

int main()
{
	int n,a;
	cin >> n;
	long long s = 0;
	int best = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a;
		s += a;
		occ[s]++;
		best = max(best,occ[s]);
	}
	cout << n-best << '\n';
}