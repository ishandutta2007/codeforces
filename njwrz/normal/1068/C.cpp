#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector <pair<int,int> > v[105];
int main(){
	int n,x,y,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)v[i].pb(make_pair(i,i+50000000));
	for(int i=0;i<m;i++){
		cin>>x>>y;
		v[x].pb(make_pair(x,i+1));
		v[y].pb(make_pair(y,i+1));
	}
	for(int i=1;i<=n;i++){
		cout<<v[i].size()<<'\n';
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j].first<<' '<<v[i][j].second<<'\n';
		}
	}
	return 0;
}