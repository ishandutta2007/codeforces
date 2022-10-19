#include <iostream>
#include <queue>

using namespace std;

struct T
{
	int x , num;
	T(int x = 0 , int num = 0) : x(x) , num(num){}
};

int n , m;
int w[100010] , sum[100010];
vector <T> t[100010];
bool f[200010];
vector <int> ans;
queue <int> q; 

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> w[i];
	for(int i = 1; i <= m; i++)
	{
		int u , v;
		cin >> u >> v;
		sum[u]++;
		sum[v]++;
		t[u].push_back(T(v , i));
		t[v].push_back(T(u , i));
	}
	for(int i = 1; i <= n; i++)
		if(sum[i] <= w[i])
			q.push(i);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		for(int i = 0; i < t[temp].size(); i++)
		{
			if(f[t[temp][i].num])
				continue;
			f[t[temp][i].num] = true;
			ans.push_back(t[temp][i].num);
			if(--sum[t[temp][i].x] == w[t[temp][i].x])
				q.push(t[temp][i].x); 
		} 
	}
	if(ans.size() < m)
		cout << "DEAD" << endl;
	else
	{
		cout << "ALIVE" << endl;
		for(int i = m - 1; i >= 0; i--)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}