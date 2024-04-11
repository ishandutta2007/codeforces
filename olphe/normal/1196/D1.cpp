#include "bits/stdc++.h"

using namespace std;

int N,M,K,L,R,H,W;
//long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>K;
	while(K--){
		cin>>N>>M;
		string s;
		cin>>s;
		vector<vector<int>>sum(3,vector<int>(N));
		for(int i=0;i<N;i++){
			if(s[i]=='R')sum[0][i]++;
			if(s[i]=='G')sum[1][i]++;
			if(s[i]=='B')sum[2][i]++;
		}
		for(int j=0;j<3;j++){
			for(int i=3;i<N;i++){
				sum[j][i]+=sum[j][i-3];
				//cout<<j<<" "<<i<<" "<<sum[j][i]<<endl;
			}
		}
		int ans=MOD;
		for(int i=0;i+M<=N;i++){
			int ed=i+M-1;
			for(int j=0;j<3;j++){
				int box=M;
				for(int k=0;k<3;k++){
					int l=i+k;
					int r=l+((ed-l)/3)*3;
					//cout<<l<<" "<<r<<endl;
					if((l<N)&&l<=ed){
						box-=sum[(j+k)%3][r];
						box+=(l>=3)?sum[(j+k)%3][l-3]:0;
					}
					//cout<<box<<endl;
				}
				ans=min(ans,box);
				//cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}