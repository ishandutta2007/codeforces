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
int n,m,a[5005],b[5005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int ans=0;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(j,1,m)cin>>b[j];
	FOR(i,1,n){
		int t=a[i];
		for(int j=2;j*j<=a[i];j++){
			if(t%j==0){
				int f=((*lower_bound(b+1,b+m+1,j))==j)?-1:1;
				while(t%j==0){
					t/=j;ans+=f;
				}
			} 
		}
		if(t!=1){
			ans+=((*lower_bound(b+1,b+m+1,t))==t)?-1:1;
		}
	}
	int gcd[5005];
	FOR(i,1,n)gcd[i]=__gcd(gcd[i-1],a[i]);
	for(int i=n;i>=1;i--){
		int sum=0;
		int t=gcd[i];
		for(int j=2;j*j<=gcd[i];j++){
			if(t%j==0){
				int f=((*lower_bound(b+1,b+m+1,j))==j)?1:-1;
				while(t%j==0){
					t/=j;sum+=f;
				}
			} 
		}
		if(t!=1){
			sum+=((*lower_bound(b+1,b+m+1,t))==t)?1:-1;
		}
		sum*=i;
		if(sum>0){
			ans+=sum;
			for(int j=1;j<i;j++)gcd[j]/=gcd[i];
		}
	}
	cout<<ans;
	RE 0;
}