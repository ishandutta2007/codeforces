#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[1000005];
int check(int x){
	int re=0,sum=0;
	FOR(i,1,n){
		sum=(sum+a[i])%x;
		re+=min(sum,x-sum);
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int sum=0;
	FOR(i,1,n)cin>>a[i],sum+=a[i];
	if(!sum){
		cout<<0;RE 0;
	}
	if(sum==1){
		cout<<-1;RE 0;
	}
	int t=sum,ans=1e18;
	for(int i=2;i*i<=t;i++){
		if(sum%i==0){
			ans=min(ans,check(i));
			while(sum%i==0)sum/=i;
		}
	}
	if(sum>1){
		ans=min(ans,check(sum));
	}
	cout<<ans;
	RE 0;
}