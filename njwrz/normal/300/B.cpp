#include <bits/stdc++.h>
using namespace std;
vector<int> a[51];int n,m,l,p[4];bool f[51];
queue<int> ans;
queue<int> ansp[51];
void dfs(int id){
	if(f[id])return ;
	f[id]=1;
	l++;ans.push(id);
	for(int i=0;i<a[id].size();i++)dfs(a[id][i]);
}
int main(){
	int x,y,t;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			l=0;
			dfs(i);
			if(l>3){
				cout<<-1;return 0;
			}
			p[l]++;
			while(!ans.empty()){
				t=ans.front();ansp[l].push(t);
				ans.pop();
			}
		}
	}
	int ans=0;
	if(p[2]>p[1]){
		cout<<-1;return 0;
	}
	for(int i=0;i<p[2];i++){
		cout<<ansp[2].front()<<' ';ansp[2].pop();
		cout<<ansp[2].front()<<' ';ansp[2].pop();
		cout<<ansp[1].front()<<'\n';ansp[1].pop();
	}
	p[1]-=p[2];
	while(!ansp[1].empty()){
		cout<<ansp[1].front()<<' ';ansp[1].pop();
		cout<<ansp[1].front()<<' ';ansp[1].pop();
		cout<<ansp[1].front()<<'\n';ansp[1].pop();
	}
	while(!ansp[3].empty()){
		cout<<ansp[3].front()<<' ';ansp[3].pop();
		cout<<ansp[3].front()<<' ';ansp[3].pop();
		cout<<ansp[3].front()<<'\n';ansp[3].pop();
	}
	return 0;
}