#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
int n,T,a[200001],t[200001],sumt;
vector<int> v[200001];
priority_queue<pair<int,int> > pq;
bool used[200001];
int main(){
	scanf("%d%d",&n,&T);
	F(i,1,n) scanf("%d%d",a+i,t+i), v[a[i]].push_back(i);
	dF(i,n,0){
		int siz=v[i].size();
		F2(j,0,siz){
			pq.push(make_pair(t[v[i][j]],v[i][j]));
			sumt+=t[v[i][j]]; used[v[i][j]]=1;
			while(pq.size()>i)
				sumt-=pq.top().first,
				used[pq.top().second]=0,
				pq.pop();
		}
		while(pq.size()>i)
			sumt-=pq.top().first,
			used[pq.top().second]=0,
			pq.pop();
//		printf("%d %d %d\n",i,pq.size(),sumt);
		if(pq.size()>=i&&sumt<=T){
			printf("%d\n%d\n",i,i);
			F(i,1,n) if(used[i]) printf("%d ",i);
			return 0;
		}
	}
	return 0;
}