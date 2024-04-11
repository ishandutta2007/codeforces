#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int dp[50][50][50][50];

int Search(int l,int r,int d,int u,const vector<vector<int>>&hsum,const vector<vector<int>>&wsum){
	if(l>r||d>u)return 0;
	if(dp[l][r][d][u]>=0)return dp[l][r][d][u];
	int ret=max(r-l+1,u-d+1);
	//cout<<l<<" "<<r<<" "<<d<<" "<<u<<" "<<ret<<endl;
	for(int i=l;i<=r;i++){
		int box=hsum[u][i];
		if(d)box-=hsum[d-1][i];
		if(!box)ret=min(ret,Search(l,i-1,d,u,hsum,wsum)+Search(i+1,r,d,u,hsum,wsum));
	}
	for(int i=d;i<=u;i++){
		int box=wsum[i][r];
		if(l)box-=wsum[i][l-1];
		if(!box)ret=min(ret,Search(l,r,d,i-1,hsum,wsum)+Search(l,r,i+1,u,hsum,wsum));
	}
	dp[l][r][d][u]=ret;
	//cout<<l<<" "<<" "<<r<<" "<<d<<" "<<u<<" "<<dp[l][r][d][u]<<endl;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	vector<string>s(N);
	for(auto &i:s)cin>>i;
	for(int i=0;i<50;i++)for(int j=0;j<50;j++)for(int k=0;k<50;k++)for(int l=0;l<50;l++)dp[i][j][k][l]=-1;
	vector<vector<int>>hsum(N,vector<int>(N));
	vector<vector<int>>wsum(N,vector<int>(N));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			hsum[i][j]=wsum[i][j]=s[i][j]=='#';
		}
	}
	for(int i=0;i<N;i++){
		for(int j=1;j<N;j++){
			wsum[i][j]+=wsum[i][j-1];
			hsum[j][i]+=hsum[j-1][i];
		}
	}
	cout<<Search(0,N-1,0,N-1,hsum,wsum)<<endl;
	return 0;
}