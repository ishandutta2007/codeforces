#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,d,x,y;
	cin>>n>>k>>d;
	queue<pair<int,int>> Qu;
	int visited[n+1]={0};
	ll r;
	map<ll,int> m;
	std::vector<int> edges[n+1];
	int edgerem=0;
	for(int i=0;i<k;i++)
	{
		cin>>x;
		if(!visited[x]){
			Qu.push(mp(x,0));
			visited[x]=1;
		}
	}
	for(int i=0;i<(n-1);i++)
	{
		cin>>x>>y;
		edges[x].pb(y);
		edges[y].pb(x);
		if(x<y){
			r=(ll)((ll)x*(1000000)+(ll)y);
			m.insert(mp(r,i+1));
		}
		else{
			r=(ll)((ll)y*(1000000)+(ll)x);
			m.insert(mp(r,i+1));	
		}
	}
	std::vector<int> ans;
	pair<int,int> p;
	while(!Qu.empty()){
		p=Qu.front();
		Qu.pop();
		x=p.first;
		y=p.second;
		for(int i : edges[x]){
			if(!visited[i]){
				Qu.push(mp(i,x));
				visited[i]=visited[x]+1;
			}
			else if(visited[i]&&i!=y){
				if(i<x){
					edgerem++;
					r=(ll)((ll)i*(1000000)+(ll)x);
					ans.pb(m[r]);
				}
			}
		}
	}
	cout<<edgerem<<"\n";
	for(int i=0;i<edgerem;i++)
	{
		cout<<ans[i]<<" ";
	}
}