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
int n,m,to[100005],pre[100005],to2[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int B=sqrt(n)/2.5+1;
	FOR(i,1,n)cin>>to[i];
	FOR(i,1,n){
		int t=i;
		pre[to[i]]=i;
		FOR(j,1,B){
			t=to[t];
		}
		to2[i]=t;
	}
	FOR(i,1,m){
		int tap;
		cin>>tap;
		int x,y;
		cin>>x>>y;
		if(tap==1){
			swap(to[x],to[y]);
			swap(pre[to[x]],pre[to[y]]);
			int now=x;
			FOR(j,1,B){
				now=to[now];
			}
			int tx=x;
			FOR(j,1,B+1){
				to2[tx]=now;
				now=pre[now];
				tx=pre[tx];
			}
			now=y;
			FOR(j,1,B){
				now=to[now];
			}
			tx=y;
			FOR(j,1,B+1){
				to2[tx]=now;
				now=pre[now];
				tx=pre[tx];
			}
		}else{
			FOR(j,1,y/B)x=to2[x];
			y%=B;
			FOR(j,1,y)x=to[x];
			cout<<x<<'\n';
		}
	}
	RE 0;
}