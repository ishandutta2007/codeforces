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
int dis[2005];
V<P<int,int> > v;
int n;
void qus(int x){
	printf("? %d\n",x);
	fflush(stdout);
	FOR(i,1,n){
		scanf("%d",&dis[i]);
	}
}
signed main(){
	v.clear();
	scanf("%d",&n);
	qus(1);
	int cnt=0;
	FOR(i,1,n)if(dis[i]&1)cnt++;
	FOR(i,1,n){
		if(dis[i]==1)v.PB(MP(1,i));
	}
	V<int> q;
	if(cnt<n/2){
		FOR(i,1,n)if(dis[i]&1)q.PB(i);
		v.clear();
	}else {
		FOR(i,1,n)if(!(dis[i]&1))q.PB(i);
	}
	for(auto u:q){
		if(u==1)continue;
		qus(u);
		FOR(i,1,n){
			if(dis[i]==1){
				v.PB(MP(u,i));
			}
		}
	}
	printf("!\n");
	for(auto u:v){
		printf("%d %d\n",u.F,u.S);
	}
	fflush(stdout);
	RE 0;
}