#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int A[50];
int N;

int main()
{
	cin >> N;
	set<int> M;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		M.insert(A[i]);
	}
	for(int i=0;i<N;i++)
	{
		if(M.find(A[i]-1) != M.end() && M.find(A[i]-2) != M.end())
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}