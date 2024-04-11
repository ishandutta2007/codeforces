#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,de[100005];
V<int> v[100005];
void dfs(int p,int fa){
	for(auto u:v[p])if(u!=fa){
		de[u]=de[p]+1;
		dfs(u,p);
	}
}
int main(){
	double ans=0;
	int x,y;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		v[x].PB(y);
		v[y].PB(x);
	}
	de[1]=1;
	dfs(1,-1);
	FOR(i,1,n)ans+=1.0/de[i];
	printf("%.10f",ans);
	RE 0;
}