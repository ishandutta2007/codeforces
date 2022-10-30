#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int n;
int p[55],dp[55][2][2];
int dfs(int x,int f1,int f2){
	if(dp[x][f1][f2]!=-1)RE dp[x][f1][f2];
	int m=n-x+1;
	if(x>m)RE 1;
	int re=0;
	FOR(fi,0,1){
		FOR(se,0,1){
			if(p[x]!=-1&&p[x]!=fi||p[m]!=-1&&p[m]!=se)continue;
			if(f1&&se<fi||f2&&!se<fi||x==m&&fi!=se)continue;
			re+=dfs(x+1,f1&&(se==fi),f2&&se!=fi); 
		}
	}
	RE dp[x][f1][f2]=re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;
	k++;
	FILL(dp,-1);
	FILL(p,-1);
	p[1]=0;
	if(dfs(1,1,1)<k){
		cout<<-1;RE 0;
	}
	FOR(i,2,n){
		FILL(dp,-1);p[i]=0;
		int t=dfs(1,1,1);
		if(t<k){
			k-=t;
			p[i]=1;
		}
	}
	FOR(i,1,n)cout<<p[i];
	RE 0;
}