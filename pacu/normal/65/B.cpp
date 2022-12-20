#include <iostream>
#include <vector>
using namespace std;

int change(int x,int i,int val)
{
	char s[5];
	sprintf(s,"%d",x);
	s[i] = ((char)val)+'0';
	sscanf(s,"%d",&x);
	return x;
}

int main()
{
	int N;
	cin >> N;
	int x;
	int prev = 1000;
	vector<int> ans;
	for(int i=0;i<N;i++)
	{
		cin >> x;
		int best = 9999;
		for(int j=0;j<4;j++)
			for(int v=0;v<=9;v++)
			{
				int y = change(x,j,v);
				if(y >= prev)
					best = min(best,y);
			}
		if(best > 2011)
		{
			cout << "No solution" << endl;
			return 0;
		}
		ans.push_back(best);
		prev = best;
	}
	for(int i=0;i<N;i++)
		cout << ans[i] << endl;
	return 0;
}