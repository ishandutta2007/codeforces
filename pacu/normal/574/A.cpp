#include <iostream>
#include <set>
using namespace std;

multiset<int,greater<int> > M;

int main()
{
	int N;
	int A[100];
	int total = 0;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		if(i)
			M.insert(A[i]);
	}
	int ans = 0;
	int cur;
	while(A[0] <= *M.begin())
	{
		A[0]++;
		cur = *M.begin();
		M.erase(M.begin());
		M.insert(cur-1);
		ans++;
	}
	cout << ans << '\n';
}