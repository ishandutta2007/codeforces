#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool vis[100000];
int p[100000];
int N;

vector<int> cyc[100000];

vector<pair<int,int> > ans;

int cid[100000];

bool cmp(int a,int b)
{
	return cyc[a].size() < cyc[b].size();
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> p[i];
		p[i]--;
	}
	int C = 0;
	for(int i=0;i<N;i++)
	{
		if(vis[i]) continue;
		vis[i] = 1;
		cyc[C].push_back(i);
		int j = p[i];
		while(j != i)
		{
			vis[j] = 1;
			cyc[C].push_back(j);
			j = p[j];
		}
		cid[C] = C;
		C++;
	}
	sort(cid,cid+C,cmp);
	if(cyc[cid[0]].size() > 2)
	{
		cout << "NO\n";
		return 0;
	}
	if(cyc[cid[0]].size() == 2)
		ans.push_back(make_pair(cyc[cid[0]][0],cyc[cid[0]][1]));
	for(int i=1;i<C;i++)
	{
		if(cyc[cid[i]].size() % cyc[cid[0]].size())
		{
			cout << "NO\n";
			return 0;
		}
		int k = 0;
		for(int j=0;j<cyc[cid[i]].size();j++)
		{
			ans.push_back(make_pair(cyc[cid[0]][k],cyc[cid[i]][j]));
			k = (k+1)%cyc[cid[0]].size();
		}
		cout << '\n';
	}
	cout << "YES\n";
	for(int i=0;i<N-1;i++)
		cout << ans[i].first+1 << ' ' << ans[i].second+1 << '\n';
}