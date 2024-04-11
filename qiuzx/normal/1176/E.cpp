#include <bits/stdc++.h>
#define N 200010
using namespace std;
int t,n,m,u,v;
vector<int> ft[N],odd,even;
int main(){
	int i,x,st;
	queue<long long> q,step;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			ft[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			ft[u].push_back(v);
			ft[v].push_back(u);
		}
		odd.clear();
		even.clear();
		bool book[N]={};
		q.push(1);
		step.push(0);
		even.push_back(1);
		book[1]=true;
		while(!q.empty())
		{
			x=q.front();
			st=step.front();
			q.pop();
			step.pop();
			for(i=0;i<ft[x].size();i++)
			{
				if(!book[ft[x][i]])
				{
					book[ft[x][i]]=true;
					q.push(ft[x][i]);
					step.push(st+1);
					if(st%2==0)
					{
						odd.push_back(ft[x][i]);
					}
					else
					{
						even.push_back(ft[x][i]);
					}
				}
			}
		}
		if(odd.size()*2<=n)
		{
			cout<<odd.size()<<endl;
			for(i=0;i<odd.size();i++)
			{
				cout<<odd[i]<<" ";
			}
		}
		else
		{
			cout<<even.size()<<endl;
			for(i=0;i<even.size();i++)
			{
				cout<<even[i]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}