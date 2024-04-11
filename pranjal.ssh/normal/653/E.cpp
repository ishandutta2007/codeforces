#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> g;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	g.resize(n);
	for(int i=1;i<=m;++i){
		int x,y;;
		cin>>x>>y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}
	for(int i=0;i<n;++i)sort(g[i].begin(),g[i].end());
	set<int> uv;
	for(int i=1;i<n;++i)uv.insert(i);
	int ctr=0,no=0;
	
	for(int i=1;i<n;++i){
		if(binary_search(g[0].begin(),g[0].end(),i))continue;
		++no;
		auto _it = uv.find(i);
		if(_it==uv.end())continue;
		uv.erase(_it);
		{
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int now = q.front();
				q.pop();
				vector<int> yo;
				for(auto it:uv){
					if(binary_search(g[now].begin(),g[now].end(),it))continue;
					q.push(it);yo.push_back(it);
				}
				for(auto it:yo)uv.erase(it);
			}
		}
		++ctr;
	}
	if(uv.size()>0 or k>no or k<ctr)cout<<"im";
	cout<<"possible";
	return 0;
}