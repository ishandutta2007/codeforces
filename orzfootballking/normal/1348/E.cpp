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
int n,k,a[505],b[505]; 
int sum,sum1,sum2;
bool f[505][505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n){
		cin>>a[i]>>b[i];
		sum1+=a[i];
		sum2+=b[i];
		sum+=a[i]+b[i];
	}
	sum/=k;
	if(sum1/k+sum2/k==sum){
		cout<<sum;RE 0;
	}
	f[0][0]=1;
	FOR(i,1,n){
		rep(j,0,k)f[i][j]=f[i-1][j];
		rep(j,1,k){
			if(j<=a[i]&&(k-j)<=b[i]){
				rep(p,0,k)f[i][(p+j)%k]|=f[i-1][p];
			}
		}
	}
	rep(i,1,k){
		if(i>sum1||(k-i)>sum2)continue;
		if((sum1-i)/k+(sum2-(k-i))/k+1==sum){
			if(f[n][i]){
				cout<<sum;RE 0;
			}
		}
	}
	cout<<sum-1;
	RE 0;
}