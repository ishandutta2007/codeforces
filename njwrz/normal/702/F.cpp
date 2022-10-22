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
int val[200005],ans[200005],hav[200005],pos[200005];
int tag[200005];
P<int,int> p[200005];
int n,m;
int sum[200005],cnt[200005],sum2[200005],cnt2[200005];
V<int> ins[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>p[i].S>>p[i].F;
		p[i].F=-p[i].F;
	}
	sort(p+1,p+n+1);
	FOR(i,1,n){
		val[i]=p[i].S;
		tag[i]=0;
		while((1<<(tag[i]+1))<=val[i])tag[i]++;
	}
	cin>>m;
	FOR(i,1,m)cin>>hav[i];
	for(int pw=30;pw>=0;pw--){
		FOR(i,1,n){
			if(tag[i]<=pw)sum[i]=val[i],cnt[i]=1;
			else sum[i]=0,cnt[i]=0;
			if(tag[i]<pw)sum2[i]=val[i],cnt2[i]=1;
			else sum2[i]=0,cnt2[i]=0;
			sum[i]+=sum[i-1];
			sum2[i]+=sum2[i-1];
			cnt[i]+=cnt[i-1];
			cnt2[i]+=cnt2[i-1];
			ins[i].clear();
		}
		FOR(i,1,m){
			int it=upb(sum+1,sum+n+1,sum[pos[i]]+hav[i])-sum-1;
			if(it>pos[i]){
				hav[i]-=sum[it]-sum[pos[i]];
				ans[i]+=cnt[it]-cnt[pos[i]];
				pos[i]=it;
			}
			gmax(it,pos[i]);
			if(it<n)ins[it+1].PB(i);
		}
		priority_queue<P<int,int> > q;
		FOR(i,1,n){
			for(auto u:ins[i])q.emplace(MP(hav[u]+sum2[pos[u]],u));
			if(tag[i]==pw){
				while(!q.empty()&&q.top().F>=val[i]+sum2[i]){
					P<int,int> now=q.top();q.pop();
					ans[now.S]+=1+cnt2[i]-cnt2[pos[now.S]];
					hav[now.S]-=sum2[i]-sum2[pos[now.S]]+val[i];
					pos[now.S]=i;
				}
			}
		}
	}
	FOR(i,1,m)cout<<ans[i]<<' ';
	RE 0;
}