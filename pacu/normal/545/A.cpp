#include <iostream>
#include <vector>
using namespace std;

int A[100][100];
int N;

int main()
{
	cin >> N;
	bool good;
	vector<int> ans;
	for(int i=0;i<N;i++)
	{
		good = 1;
		for(int j=0;j<N;j++)
		{
			cin >> A[i][j];
			if((A[i][j]==1)||(A[i][j]==3))
				good = 0;
		}
		if(good)
			ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i]+1 << " ";
	cout << endl;
}