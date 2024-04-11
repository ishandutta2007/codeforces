#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int n,m,s,t,x,y;
int dg[1000001],f[1000001],to[1000001],ne[1000001];
int d[1000001];
bool ok[1000001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=f[x];
	f[x]=k;
}
inline void dij(int b){
	memset(d,-1,sizeof(d));
	memset(ok,1,sizeof(ok));
	d[b]=0;
	q.push(make_pair(0,b));
	while(!q.empty()){
		if(d[q.top().second]!=q.top().first){
			q.pop();
			continue;
		}
		x=q.top().second,q.pop();
		for(int k=f[x];k;k=ne[k]){
			dg[to[k]]--;
			if(d[to[k]]!=-1&&d[x]!=d[to[k]]-1) ok[to[k]]=0;
			if(dg[to[k]]==0){
				if(ok[to[k]]){
					d[to[k]]=d[x];
					q.push(make_pair(d[to[k]],to[k]));
				}
				else if(d[to[k]]==-1||d[x]+1<d[to[k]]){
					d[to[k]]=d[x]+1;
					q.push(make_pair(d[to[k]],to[k]));
				}
			}
			else if(d[to[k]]==-1||d[x]+1<d[to[k]]){
				d[to[k]]=d[x]+1;
				q.push(make_pair(d[to[k]],to[k]));
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		dg[x]++;
		link(y,x,i);
	}
	scanf("%d%d",&s,&t);
	dij(t);
	cout<<d[s];
}