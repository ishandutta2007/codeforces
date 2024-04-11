#pragma GCC optimize(2)
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
int n,m,len[12],a[12][42],to;
void dfs(V<int> num,int now){
	if(now==m+1){
		rep(i,0,n)if((i&&num[i-1]==1&&num[i]!=1)||num[i]==-1){
			cout<<"REJECTED\n";exit(0);
		}
		RE ;
	}
	int cntxy=0,cntwz=0,cntdy=0;
	FOR(i,1,len[now]){
		cntxy+=num[a[now][i]-1]==0;
		cntdy+=num[a[now][i]-1]==1;
		cntwz+=num[a[now][i]-1]==-1;
	}
	FOR(i,1,cntxy)num[a[now][i]-1]=0;
	FOR(i,cntxy+1,cntxy+cntwz+cntdy)num[a[now][i]-1]=1;
	FOR(mi,0,cntwz){
		if(mi)num[a[now][cntxy+mi]-1]=0;
		dfs(num,now+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<"ACCEPTED\n";RE 0;
	}
	FOR(i,1,m){
		cin>>len[i];
		FOR(j,1,len[i])cin>>a[i][j];
	}
	V<int> v(n,-1);
	dfs(v,1);
	cout<<"ACCEPTED\n";
	RE 0;
}