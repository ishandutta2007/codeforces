#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
P<int,int> p[200005];
int n,q,B,f[200005],lst[200005],lsta[200005],ans,tim[205][2005],d[205][2005],sum[205][2005],len[200005],mi[200005];
P<int,int> num[505];
void solve(int x,int ti,int &hi){
	int l=(x-1)*B+1,r=min(x*B,n);
	if(!f[x]){
		FOR(i,l,r){
			lsta[i]=lst[x];
			mi[i]=0;
		}
	}
	FOR(i,l,r){
		int now=min((ti-lsta[i])*p[i].S+mi[i],p[i].F);
		if(hi<=now){
			mi[i]=now-hi;hi=0;f[x]=1;lsta[i]=ti;RE;
		}else hi-=now,lsta[i]=ti,mi[i]=0;
	}
	f[x]=0;
	lst[x]=ti;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>p[i].F>>p[i].S;
	FOR(i,1,n)lsta[i]=lst[i]=-1e9,f[i]=1;
	int q;
	cin>>q;
	B=sqrt(n*18);
	FOR(i,1,(n+B-1)/B){
		int l=(i-1)*B+1,r=min(i*B,n);
		int cnt=0;
		FOR(j,l,r){
			num[++cnt]=MP((p[j].F+p[j].S-1)/p[j].S,j);
		}
		len[i]=cnt;
		sort(num+1,num+cnt+1);
		FOR(j,1,cnt)tim[i][j]=num[j].F,sum[i][j]=p[num[j].S].F+sum[i][j-1];
		for(int j=cnt;j>=1;j--)d[i][j]=d[i][j+1]+p[num[j].S].S;
	}
	FOR(_,1,q){
		int ti,hi;
		cin>>ti>>hi;
		FOR(i,1,(n+B-1)/B){
			if(f[i]){
				solve(i,ti,hi);
				if(hi==0)break;
			}else{
				int res=ti-lst[i];
				int it=upb(tim[i]+1,tim[i]+len[i]+1,res)-tim[i]-1;
				int now=sum[i][it]+res*d[i][it+1];
				if(now>=hi){
					solve(i,ti,hi);break;
				}else hi-=now,lst[i]=ti;
			}
		}
		ans+=hi;
	}
	cout<<ans;
	RE 0;
}