#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
bool win(ll s,ll e){
	if(s==e){
		return 0;
	}
	if(e&1){
		return s%2==0;
	}
	if(s>e/2){
		return s%2==1;
	}
	if(s>e/4){
		return 1;
	}
	return win(s,e/4);
}
bool lose(ll s,ll e){
	if(2*s>e){
		return 1;
	}
	return win(s,e/2);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int w[n],l[n];
	int dp[n][2];
	for(int i=0;i<n;i++){
		ll s,e;
		cin>>s>>e;
		int flag=0;
		if(s==1&&e!=1){
			s=2;
			flag=1;
		}
		w[i]=win(s,e);
		l[i]=lose(s,e);
		if(flag){
			w[i]^=1;
			l[i]^=1;
		}
		if(i==0){
			dp[i][0]=w[i];
			dp[i][1]=l[i];
		}
		else{
			dp[i][0]=dp[i][1]=0;
			if(dp[i-1][0]){
				if(w[i]==0){
					dp[i][0]=1;
				}
				if(l[i]==0){
					dp[i][1]=1;
				}
			}
			if(dp[i-1][1]){
				if(w[i]==1){
					dp[i][0]=1;
				}
				if(l[i]==1){
					dp[i][1]=1;
				}
			}
		}
	}
	cout<<dp[n-1][0]<<" "<<dp[n-1][1]<<endl;
	return 0;
}