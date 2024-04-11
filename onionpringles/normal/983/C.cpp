#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,vector<int>> tii;
map<tii,int> dist,chk;
priority_queue<pair<int,tii>> pq;
pair<int,int> x[2000];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		int s,e;scanf("%d%d",&s,&e);s--;e--;
		x[i]={s,e};
	}
	dist[{0,0,vector<int>()}]=0;
	pq.push({0,{0,0,vector<int>()}});
	while(!pq.empty()){
		auto T=pq.top().second;pq.pop();
		if(chk.count(T))continue;
		chk[T]=1;
		if(get<1>(T)==n){
			return !printf("%d\n",dist[T]);
		}
		int fl=get<0>(T),left=get<1>(T);
		vector<int> cur=get<2>(T);
		int D=dist[T];
		
		if(fl<8){
			auto it=dist.find({fl+1,left,cur});
			if(it == dist.end() || it->second > D+1){
				dist[{fl+1,left,cur}]=D+1;
				pq.push({-D-1,{fl+1,left,cur}});
			}
		}
		if(fl){
			auto it=dist.find({fl-1,left,cur});
			if(it == dist.end() || it->second > D+1){
				dist[{fl-1,left,cur}]=D+1;
				pq.push({-D-1,{fl-1,left,cur}});
			}
		}
		
		int c=0;
		vector<int> W;
		for(auto &x:cur){
			if(x!=fl)W.push_back(x);
			else c++,left++;
		}
		while(W.size() < 4){
			int next=left + W.size();
			if(next==n)break;
			if(x[next].first==fl){
				W.push_back(x[next].second);
				c++;
			}
			else break;
		}
		sort(W.begin(),W.end());
		
		auto it=dist.find({fl,left,W});
		if(it==dist.end() || it->second > D+c){
			dist[{fl,left,W}]=D+c;
			pq.push({-D-c,{fl,left,W}});
		}
		
	}
	
}