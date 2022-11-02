#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int dp[(1<<24)],n,cost[30][30],er[30];
P<int,int> p[30],last[(1<<24)];
void print(int now){
	if(!now)RE;
	if(last[now].S>=0){
		print(now^er[last[now].F]^er[last[now].S]);
		cout<<last[now].F+1<<' '<<last[now].S+1<<" 0 ";
	}else {
		print(now^er[last[now].F]);cout<<last[now].F+1<<" 0 ";
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int p1,p2;
    cin>>p1>>p2;
	cin>>n;p[n].F=p1;p[n].S=p2;
	FOR(i,0,n-1){
		cin>>p[i].F>>p[i].S;
	}
	FOR(i,0,n){
		FOR(j,0,n){
			cost[i][j]=pow((p[i].F-p[j].F),2)+pow(p[i].S-p[j].S,2);
		}
	}
	er[0]=1;
	FOR(i,1,n)er[i]=er[i-1]*2;
	FOR(i,1,er[n]-1)dp[i]=2147483647;
	int st,t;
	FOR(i,0,er[n]-2){
		if(dp[i]==2147483647)continue;
		st=-1;
		FOR(j,0,n-1){
			if(!(i&er[j])){
				st=j;break;
			}
		}
		t=i^(1<<st);
		if(dp[t]>dp[i]+cost[n][st]*2){
			dp[t]=dp[i]+cost[n][st]*2;
			last[t].F=st;last[t].S=-1;
		}
		for(int j=st+1;j<n;j++){
			if(!(i&er[j])){
				if(dp[i]+cost[st][j]+cost[j][n]+cost[st][n]<dp[t^er[j]]){
					dp[t^er[j]]=dp[i]+cost[st][j]+cost[j][n]+cost[st][n];
					last[t^er[j]].F=st;last[t^er[j]].S=j;
				}
			}
		}
	}
	cout<<dp[er[n]-1]<<'\n';
	cout<<"0 ";
	print(er[n]-1);
	RE 0;
}