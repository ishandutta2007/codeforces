#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	vector<int> A;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		A.push_back(0);
		cin >> A[i];
	}
	sort(A.begin(),A.end());
	long long sm = 0;
	int mul;
	for(int i=0;i<N;i++)
	{
		sm += ((long long)min(2+i,N))*A[i];
	}
	cout << sm << endl;
}