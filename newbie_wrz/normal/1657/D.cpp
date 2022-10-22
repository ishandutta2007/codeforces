#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,m;
P<int,int> p[300005];
int num[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		int cost,h,w;
		cin>>cost>>h>>w;
		gmax(num[cost],h*w);
	}
	FOR(i,1,m){
		gmax(num[i],num[i-1]);
		for(int j=i+i;j<=m;j+=i)gmax(num[j],num[i]*(j/i));
	}
	int q;
	cin>>q;
	FOR(_,1,q){
		int x,y;
		cin>>x>>y;
		x*=y;
		int it=upb(num+1,num+m+1,x)-num;
		if(it>m)cout<<-1<<' ';
		else cout<<it<<' ';
	}
	RE 0;
}