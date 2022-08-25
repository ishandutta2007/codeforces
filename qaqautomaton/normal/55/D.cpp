/*
Author: CNYALI_LK
LANG: C++
PROG: CF55D.cpp
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define aint(x) x.begin(),x.end()
#define end(...) {printf(__VA_ARGS__);exit(0);}
using namespace std;
const double eps=1e-8;
const double PI=acos(-1.0);
typedef long long ll;
template<class T>void chkmin(T &a,T b){a=a<b?a:b;}
template<class T>void chkmax(T &a,T b){a=a>b?a:b;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
int a[102],t;
ll dp[20][2560][300];
ll dfs(int md,int cx,int w,int bj){
	if(!bj&&dp[w][md][cx]+1)return dp[w][md][cx];
	if(w==0){
		for(int i=0;i<8;++i){
			if((cx&(1<<i))&&(md%(i+2))){
				return dp[w][md][cx]=0;
			}
		}
		return dp[w][md][cx]=1;	
	}
	if(bj){
		ll ans=0;
		for(int i=0;i<a[w];++i){
			if(i<2){
				ans+=dfs((md*10+i)%2520,cx,w-1,0);
			}
			else ans+=dfs((md*10+i)%2520,cx|(1<<(i-2)),w-1,0);
		}
		if(a[w]<2)ans+=dfs((md*10+a[w])%2520,cx,w-1,1);
		else ans+=dfs((md*10+a[w])%2520,cx|(1<<(a[w]-2)),w-1,1);
		return ans;
	}
	else{
		dp[w][md][cx]=0;
		for(int i=0;i<10;++i){
			if(i<2){
				dp[w][md][cx]+=dfs((md*10+i)%2520,cx,w-1,0);
			}
			else dp[w][md][cx]+=dfs((md*10+i)%2520,cx|(1<<(i-2)),w-1,0);
		}
		return dp[w][md][cx]; 

	}
}
ll f(ll x){
	t=0;
	while(x){
		a[++t]=x%10;
		x/=10;
	}
	return dfs(0,0,t,1);
}
int main(){
#ifdef cnyali_lk
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	ll t,l,r;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t){
		--t;
		cin>>l>>r;
		cout<<f(r)-f(l-1)<<endl;
	}
	return 0;
}