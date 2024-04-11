#include <iostream>
#include <vector>
using namespace std;

bool seen[1001];

int A[1000];
vector<int> ans;

int main()
{
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		int b = i;
		for(int j=2;j*j<=i;j++)
		{
			if(!(b%j))
			{
				int c = 1;
				while(!(b%j))
					b /= j, c *= j;
				if(!seen[c]) seen[c] = 1, ans.push_back(c);
			}
		}
		if(!seen[b] && b>1) ans.push_back(b), seen[b] = 1;
	}
	cout << ans.size() << '\n';
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << ' ';
	cout << '\n';
}