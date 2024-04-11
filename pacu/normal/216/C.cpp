#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N,M,K;
	priority_queue<int,vector<int>,greater<int> > P;
	vector<int> ans;
	cin >> N >> M >> K;
	for(int i=0;i<K;i++)
	{
		ans.push_back(0);
		P.push(0+N-1);
	}
	for(int d=0;d<=(N+M);d++)
	{
		while((P.size()>0)&&(P.top()==(d-1)))
			P.pop();
		if(P.size()==0)
		{
			ans.push_back(d-1);
			P.push((d-1)+N-1);
		}
		if(d<(N+M))
		{
			while(P.size()<K)
			{
				ans.push_back(d);
				P.push(d+N-1);
			}
		}
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i]+1 << " ";
	return 0;
}