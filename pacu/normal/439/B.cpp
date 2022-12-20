#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long n,x;
	vector<long long> sz;
	int c;
	long long time = 0;
	cin >> n >> x;
	while(cin>>c)
		sz.push_back(c);
	sort(sz.begin(),sz.end());
	for(int i=0;i<n;i++)
	{
		time += sz[i]*x;
		if(x>1) x--;
	}
	cout << time << endl;
}