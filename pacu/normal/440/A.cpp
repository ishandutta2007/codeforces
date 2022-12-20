#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int prev;
	cin >> N;
	vector<int> A;
	while(cin)
	{
		cin >> prev;
		A.push_back(prev);
	}
	sort(A.begin(),A.end());
	if(A[0]>1) cout << 1 << endl;
	for(int i=1;i<A.size();i++)
	{
		if((A[i]-A[i-1])>1) cout << A[i-1]+1 << endl;
	}
	if(A[A.size()-1]<N) cout << N << endl;
}