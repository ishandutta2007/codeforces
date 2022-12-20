#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> >edgesOut;
vector<vector<int> >edgesIn;
int cnt1[3000];
int cnt2[3000];

int main()
{
	int N,M;
	cin >> N >> M;
	int a,b;
	for(int i=0;i<N;i++)
	{
		edgesOut.push_back(vector<int>());
		edgesIn.push_back(vector<int>());
		cnt1[i] = 0;
		cnt2[i] = 0;
	}
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		edgesOut[a].push_back(b);
		edgesIn[b].push_back(a);
	}
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		for(int a=0;a<edgesOut[i].size();a++)
			cnt1[edgesOut[i][a]]++;
		for(int a=0;a<edgesIn[i].size();a++)
			cnt2[edgesIn[i][a]]++;
		for(int j=(i+1);j<N;j++)
		{
			int tot1 = 0;
			for(int a=0;a<edgesOut[j].size();a++)
			{
				cnt1[edgesOut[j][a]]++;
				if(cnt1[edgesOut[j][a]]==2)
					tot1++;
			}
			for(int a=0;a<edgesIn[j].size();a++)
			{
				cnt2[edgesIn[j][a]]++;
				if(cnt2[edgesIn[j][a]]==2)
				{
					ans += tot1;
					if(cnt1[edgesIn[j][a]]==2)
						ans--;
				}
			}
			for(int a=0;a<edgesOut[j].size();a++)
				cnt1[edgesOut[j][a]]--;
			for(int a=0;a<edgesIn[j].size();a++)
				cnt2[edgesIn[j][a]]--;
		}
		for(int a=0;a<edgesOut[i].size();a++)
			cnt1[edgesOut[i][a]]--;
		for(int a=0;a<edgesIn[i].size();a++)
			cnt2[edgesIn[i][a]]--;
	}
	cout << ans << endl;
}