#include "bits/stdc++.h"
using namespace std;

void Solve(){
	int N,a,b;
	cin>>N>>a>>b;
	vector<long long>v(N+1);
	for(int i=1;i<=N;i++)cin>>v[i];
	vector<long long>sum(N+1);
	for(int i=0;i<N;i++){
	    sum[i+1]=sum[i]+v[i+1];
	}
	long long ans=1e18;
	for(int i=0;i<N;i++){
	    long long val=v[i]*a;
	    val+=b*(sum.back()-sum[i]-v[i]*(N-i));
	    val+=v[i]*b;
	    ans=min(ans,val);
	}
	cout<<ans<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	
	return 0;
}