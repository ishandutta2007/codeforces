#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int A[100000];

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	int j = 0;
	vector<int> ans;
	for(int i=1;M>=i;i++)
	{
		while(j<N && A[j]<i) j++;
		if(j==N || A[j] != i)
		{
			ans.push_back(i);
			M -= i;
		}
	}
	cout << ans.size() << '\n';
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << ' ';
	cout << '\n';
}