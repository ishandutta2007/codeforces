#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

int main()
{
	int N;
	vector<long long> A;
	int i,j;
	cin >> N;
	for(i=0;i<100000;i++)
		A.push_back(0);
	for(i=0;i<N;i++)
	{
		cin >> j;
		A[j-1]++;
	}
	if(N==1)
	{
		cout << j << endl;
		return 0;
	}
	vector<long long> yesdp;
	vector<long long> nodp;
	yesdp.push_back(1*A[0]);
	nodp.push_back(0);
	for(i=1;i<100000;i++)
	{
		yesdp.push_back(nodp[i-1]+(i+1)*A[i]);
		if(i>1)
			nodp.push_back(max(yesdp[i-1],yesdp[i-2]));
		else
			nodp.push_back(yesdp[i-1]);
	}
	cout << max(yesdp[100000-1],nodp[100000-1]) << endl;
}