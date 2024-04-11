#include <iostream>
#include <vector>
using namespace std;

int A[1000];

int main()
{
	int N,K,P,X,Y;
	cin >> N >> K >> P >> X >> Y;
	int lower = 0;
	int cursum = 0;
	for(int i=0;i<K;i++)
	{
		cin >> A[i];
		if(A[i]<Y) lower++;
		cursum += A[i];
	}
	vector<int> ans;
	for(int i=K;i<N;i++)
	{
		if((lower+1)<=(N/2))
		{
			ans.push_back(1);
			lower++;
			cursum++;
		}
		else
		{
			ans.push_back(Y);
			cursum += Y;
		}
	}
	if((cursum>X)||(lower>(N/2)))
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i=K;i<N;i++)
		cout << ans[i-K] << " ";
	cout << endl;
	return 0;
}