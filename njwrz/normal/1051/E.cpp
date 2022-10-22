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
int num[1000005],n;
int l[1000005],tl,r[1000005],tr,dp[1000005],sum[1000005],mod=998244353;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int pos[2000005],len;
int zl[2000005],zr[2000005];
void get(int *z){
	int maxi=0;
	FOR(i,2,len){
		if(z[maxi]+maxi-1>=i){
			z[i]=z[i-maxi+1];
			gmin(z[i],z[maxi]+maxi-i);
		}
		while(i+z[i]<=len&&pos[z[i]+1]==pos[i+z[i]])z[i]++;
		if(i+z[i]>maxi+z[maxi]){
			maxi=i;
		}
	}
}
bool checkr(int x){
	int t=zr[x+tr];
	if(t>=tr)RE 0;
	if(r[t+1]<num[x+t])RE 1;
	else RE 0;
}
bool checkl(int x){
	int t=zl[x+tl];
	if(t>=tr)RE 1;
	if(l[t+1]<=num[x+t])RE 1;
	else RE 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	n=s.size();
	FOR(i,1,n)num[i]=s[i-1]-'0';
	cin>>s;
	tl=s.size();
	FOR(i,1,tl)l[i]=s[i-1]-'0';
	FOR(i,1,tl)pos[i]=l[i];
	FOR(i,1,n)pos[i+tl]=num[i];
	len=tl+n;
	get(zl);
	cin>>s;
	tr=s.size();
	FOR(i,1,tr)r[i]=s[i-1]-'0';
	FOR(i,1,tr)pos[i]=r[i];
	FOR(i,1,n)pos[i+tr]=num[i];
	len=tr+n;
	get(zr);
	dp[0]=1;sum[0]=1;
	FOR(i,1,n){
		int r=i-tl+1,l=i-tr+1;
		if(l>=1){
			if(checkr(l))l++;
		}
		gmax(l,1ll);
		if(r>=1){
			if(!checkl(r))r--;
		}
		if(l<=r){
			dp[i]=(sum[r-1]-((l>1)?sum[l-2]:0)+mod)%mod;
			if(r==i&&num[i]==0){
				add(dp[i],dp[i-1]);
			}
		}
		if(i<n&&num[i+1]==0)sum[i]=sum[i-1];
		else sum[i]=(sum[i-1]+dp[i])%mod;
	}
	cout<<dp[n];
	RE 0;
}