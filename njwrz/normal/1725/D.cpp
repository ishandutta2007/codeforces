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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int n,q,tot,sum,ans,lim;
int s[200005];
int check(int x){
	int re=0;
	if(x-20>=0)re=s[x-20];
	rep(i,max(0ll,x-19),x){
		int now=(1<<(x-i))-1;
		int ti=min(now,tot-1-i);
		if(ti>=0)re+=(ti+1)/2;
		if((tot-i)%2==1&&(tot-i)<=now&&i>=lim)re++;
	}
	RE re;
}
int num[30],len;
int check(int x,int val){
	int re=0;
	len=0;
	while(val)num[++len]=val&1,val/=2;
	if(x-20>=0)re=s[x-20];
	int it=len;
	int now=0;
	for(int i=x-1;i>=max(0ll,x-19);i--){
		if(it>=1)now=now*2+num[it],it--;else now=now*2+1;
		int ti=min(now,tot-1-i);
		if(ti>=0)re+=(ti+1)/2;
		if((tot-i)%2==1&&(tot-i)<=now&&i>=lim)re++;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	int x=0;
	sum=0,ans=0;
	while(sum+(x+2)/2<=n){
		x++;
		sum+=(x+1)/2;
		ans+=(x+1)/2*x;
	}
	x++;ans+=(n-sum)*x;
	tot=x;
	cout<<ans<<'\n';
	lim=x-(n-sum)*2+1;
	rep(i,0,x){
		s[i]=(x-1-i+1)/2;
		if(((x-i)&1)&&i>=lim){
			s[i]++;
		}
	}
	rep(i,1,x+20)s[i]+=s[i-1];
	FOR(_,1,q){
		int it;
		cin>>it;
		int l=0,r=x+18,mid,ans=-1;
		while(r>=l){
			mid=(l+r)>>1;
			if(check(mid)<it){
				ans=mid;l=mid+1;
			}else r=mid-1;
		}
		ans++;
		int ta=1;
		rep(i,0,min(19ll,ans-1)){
			ta=ta*2;
			if(check(ans,ta)>=it){
				
			}else ta++;
		}
		int out=max(0ll,ans-20);
		while(ta%2==0)ta/=2,out++;
		cout<<out+ta<<'\n';
	}
	RE 0;
}