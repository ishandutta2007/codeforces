#include <bits/stdc++.h>

using namespace std;

int n, a[500005];
priority_queue<pair<int,int>> que;
vector<pair<int,int>>ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans.clear();
		while(!que.empty())que.pop();
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if(a[i])que.emplace(a[i], i);
		}
		
		while (que.size() >= 2)
		{
			auto p = que.top(); que.pop();
			auto q = que.top(); que.pop();
			ans.emplace_back(p.second,q.second);
			if(p.first>1)que.emplace(p.first-1,p.second);
			if(q.first>1)que.emplace(q.first-1,q.second);
		}
		printf("%d\n",ans.size());
		for(auto[p,q]:ans)printf("%d %d\n",p,q);
	}

}