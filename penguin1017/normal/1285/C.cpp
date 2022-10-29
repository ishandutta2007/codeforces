#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back 
using namespace std;
const int N=2e6+9;
vi g[N];
ll a[20];
int cnt;
int main()
{
	ll n,x,y,n1;
	scanf("%lld",&n);
	ll ans=n;
	n1=n;
	for(ll i=2;i*i<=n;++i){
		if(n%i==0){
			a[cnt]=1;
			while(n%i==0){
				a[cnt]*=i;
				n/=i;
			}
			cnt++;
		}
	}
	if(n>1)a[cnt++]=n;
	rep(i,0,(1<<cnt)){
		x=1,y=1;
		rep(j,0,cnt){
			if((1<<j)&i)x*=a[j];
			else y*=a[j];
		}
		ans=min(ans,max(x,y));
	} 
	cout<<n1/ans<<' '<<ans;
 }