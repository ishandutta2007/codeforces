#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define pii pair<int,int>
#define vi vector<pii> 
#define fi first
#define se second
#define lb(x) ((x)&(-x))
#define ll long long
using namespace std;
const int N=1e5+1;
const ll maxn=1e17;
ll x[100],y[100],xp,yp,t,ax,bx,ay,by;
int cnt;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&xp,&yp,&t);
	for(int i=1;;++i){
		cnt=i;
		if(x[i-1]>=maxn/ax||y[i-1]>=maxn/ay)break;
		x[i]=x[i-1]*ax+bx;
		y[i]=y[i-1]*ay+by;
	}
	int ans=0;
	ll T;
	rep(i,0,cnt){
		rep(j,0,cnt){
			T=abs(x[i]-xp)+abs(y[i]-yp)+abs(x[i]-x[j])+abs(y[i]-y[j]);
			if(T<=t)ans=max(ans,abs(j-i)+1);
		//	cout<<T<<' '<<j-i+1<<' '<<ans<<"check\n";
		//	system("pause");
		}
	}
	cout<<ans;
	
}