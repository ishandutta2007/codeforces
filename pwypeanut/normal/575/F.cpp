#include <bits/stdc++.h>
#define fi first
#define sc second
#define IMAX 99999999999999LL
using namespace std;
typedef pair<long long ,long long > pi;

long long dp[2][10009];//i,dist
pi d[5009];
long long r[10009];//Dp(i-1,k)+D[k]
long long l[10009];//Dp(i-1,k)-D[k]
vector<long long int> dc;

int main(){
	int n,x;scanf("%d%d",&n,&x);
	dc.push_back(x);
	for(int i=0;i<n;i++){
		scanf("%I64d%I64d",&d[i].fi,&d[i].sc);
		dc.push_back(d[i].fi);
		dc.push_back(d[i].sc);
	}
	sort(dc.begin(),dc.end());
	dc.resize(unique(dc.begin(),dc.end())-dc.begin());
	int p=dc.size();
	for(int i=0;i<p;i++){
		//printf("%d ",dc[i]);
	}//printf("\n");
	for(int j=0;j<p;j++){
		dp[1][j]=abs(x-dc[j]);
		//printf("%I64d ",dp[1][j]);
	}//printf("\n");
	for(int j=0;j<p;j++){
		l[j]=dp[1][j]-dc[j];
		if(j)l[j]=min(l[j],l[j-1]);
	}
	for(int j=p-1;j>=0;j--){
		r[j]=dp[1][j]+dc[j];
		if(j<p-1)r[j]=min(r[j],r[j+1]);
	}
	/*for(int i=0;i<p;i++){
		printf("%I64d ",l[i]);
	}printf("\n");
	for(int i=0;i<p;i++){
		printf("%I64d ",r[i]);
	}printf("\n");*/
	for(int i=0;i<n;i++){
		for(int j=0;j<p;j++){
			int cost;
			if(dc[j]>=d[i].fi&&dc[j]<=d[i].sc)cost=0;
			else cost=min(abs(dc[j]-d[i].fi),abs(dc[j]-d[i].sc));
			dp[i&1][j]=IMAX;
			dp[i&1][j]=min(dp[i&1][j],cost+dc[j]+l[j]);
			dp[i&1][j]=min(dp[i&1][j],cost-dc[j]+r[j]);
			//printf("%I64d ",dp[i&1][j]);
		}
		for(int j=0;j<p;j++){
			l[j]=dp[i&1][j]-dc[j];
			if(j)l[j]=min(l[j],l[j-1]);
		}
		for(int j=p-1;j>=0;j--){
			r[j]=dp[i&1][j]+dc[j];
			if(j<p-1)r[j]=min(r[j],r[j+1]);
		}
		//printf("\n");
	}
	long long cs=IMAX;
	for(int j=0;j<p;j++){
		cs=min(cs,dp[(n-1)&1][j]);
	}
	printf("%I64d\n",cs);
}