#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N,M;
	string S[100];
	vector<int> x;
	vector<int> y;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> S[i];
		for(int j=0;j<M;j++)
		{
			if(S[i][j]=='*')
			{
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	int op = 0;
	int samey,samex;
	for(;op<3;op++)
	{
		if((x[op]==x[(op+1)%3])&&
			(y[op]==y[(op+2)%3]))
		{
			samey = (op+2)%3;
			samex = (op+1)%3;
			break;
		}
		if((x[op]==x[(op+2)%3])&&
			(y[op]==y[(op+1)%3]))
		{
			samey = (op+1)%3;
			samex = (op+2)%3;
			break;
		}
	}
	cout << x[samey]+1 << " " << y[samex]+1 << endl;
}