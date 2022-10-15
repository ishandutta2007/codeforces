#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int ,int >
using namespace std;
const long long INF = (long long)(1e18);
const int Maxn = int(3e5)+1000;
int N , M , K  , In[Maxn];
long long dis[Maxn];
vector< pii > ver[Maxn];
vector< pii > train;
 
struct X{
	bool operator ()(int a , int b){
		if(dis[a] != dis[b])
			return dis[a]<dis[b];
		else
			return a < b;
	}
};
set<int , X>S;
void dij(){
	S.clear();
	fill(dis+0, dis+Maxn ,  INF );
	dis[1] = 0;
	S.insert(1);
	while(S.empty()==false){
		int v = *(S.begin());
		S.erase(S.begin());
		for(int i = 0 ; i< ver[v].size() ;i++){
			int next = ver[v][i].first;
			long long pr =(long long) ver[v][i].second;
			if(dis[v] + pr < dis[next]){
				S.erase(next);
				dis[next] = dis[v] + pr;
				S.insert(next);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> N >> M >> K;
 	vector< pair<long long int, pair<long long int,long long > > >edgepair;
    for(int i = 0 ; i< M;i++){
		int a,b,w;
		cin >> a >> b >> w;
		ver[a].pb(mp(b , w));
		ver[b].pb(mp(a , w));
		edgepair.push_back({a,{b,w}});
	}
 	for(int i = 0 ; i< K;i++){
		int a , w;
		cin >> a >> w;
		ver[1].pb(mp(a , w) );
		train. pb(mp(a , w) );
	}
 	dij();
 	int sz=edgepair.size();
	for(int i=0;i<sz;i++)
	{
		int firstvertex=edgepair[i].first;
		int secondvertex=edgepair[i].second.first;
		int len=edgepair[i].second.second;
		if((long long int)dis[firstvertex]+len==(long long)dis[secondvertex])
		{
			In[secondvertex]++;
		}
		if((long long int)dis[secondvertex]+len==(long long)dis[firstvertex])
		{
			In[firstvertex]++;
		}
	}
 	int ans = 0;
 	for(int i = 0 ; i< train.size();i++)
	{
		if( ((long long)train[i].second == dis[train[i].first]) and In[train[i].first]==0){ans++; In[train[i].first]++;}
		
	}
	cout << K-ans << endl;
}