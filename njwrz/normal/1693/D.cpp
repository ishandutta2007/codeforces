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
int n,p[200005],premi[200005],premx[200005],nxtmi[200005],nxtmx[200005];
int l[200005],r[200005],to[200005];
set<int> num;
int getmx(){
	if(num.empty())RE 0;
	auto u=num.end();
	--u;
	RE *u;
}
int getmi(){
	if(num.empty())RE 2e9;
	RE *num.begin();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>p[i];
	stack<int> s;
	FOR(i,1,n){
		while(!s.empty()&&p[s.top()]<p[i])nxtmx[s.top()]=i,s.pop();
		if(!s.empty()){
			premx[i]=s.top();
		}
		s.emplace(i);
	}
	while(!s.empty())s.pop();
	FOR(i,1,n){
		while(!s.empty()&&p[s.top()]>p[i])nxtmi[s.top()]=i,s.pop();
		if(!s.empty()){
			premi[i]=s.top();
		}
		s.emplace(i);
	}
	int tl=n;
	for(int i=n;i>=1;i--){
		while(tl&&(getmx()<p[tl]||getmi()>p[tl]))num.emplace(p[tl]),tl--;
		l[i]=tl+1;
		num.erase(p[i]);
	}
	num.clear();
	int tr=1;
	FOR(i,1,n){
		while(tr<=n&&(getmx()<p[tr]||getmi()>p[tr]))num.emplace(p[tr]),tr++;
		r[i]=tr-1;
		num.erase(p[i]);
	}
	FOR(i,1,n){
		if(nxtmi[i]==0)nxtmi[i]=n+1;
		if(nxtmx[i]==0)nxtmx[i]=n+1;
	}
//	FOR(i,1,n)cout<<premi[i]<<' '<<premx[i]<<' '<<nxtmi[i]<<' '<<nxtmx[i]<<'\n';
	int ans=0;
	FOR(i,1,n)to[i]=i;
	P<int,int> pl,pr;
	rep(i,1,n)rep(i1,0,2)rep(i2,0,2){
		if(i==1){
			if(i1)pl=MP(0,p[1]);else pl=MP(p[1],2e9);
		}else{
			if(p[i-1]>p[i]){
				if(i1){
					pl.S=p[i],pl.F=(premi[i]>=l[i])?p[premi[i]]:0;
				}else{
					pl.S=p[i-1],pl.F=p[i];if(premi[i-1]>=l[i]&&p[premi[i-1]]>p[i])continue;
				}
			}else{
				if(i1){
					pl.F=p[i],pl.S=(premx[i]>=l[i])?p[premx[i]]:2e9;
				}else{
					pl.S=p[i],pl.F=p[i-1];if(premx[i-1]>=l[i]&&p[premx[i-1]]<p[i])continue;
				}
			}
		}
		if(i+1==n){
			if(i2)pr=MP(0,p[n]);else pr=MP(p[n],2e9);
		}else{
			if(p[i+1]<p[i+2]){
				if(i2){
					pr.S=p[i+1],pr.F=(nxtmi[i+1]<=r[i+1])?p[nxtmi[i+1]]:0;
				}else{
					pr.S=p[i+2],pr.F=p[i+1];if(nxtmi[i+2]<=r[i+1]&&p[nxtmi[i+2]]>p[i+1])continue;
				}
			}else{
				if(i2){
					pr.F=p[i+1],pr.S=(nxtmx[i+1]<=r[i+1])?p[nxtmx[i+1]]:2e9;
				}else{
					pr.S=p[i+1],pr.F=p[i+2];if(nxtmx[i+2]<=r[i+1]&&p[nxtmx[i+2]]<p[i+1])continue;
				}
			}
		}
		swap(pr.F,pr.S);
		if(pl.F<pr.F&&pl.S>pr.S)gmax(to[l[i]],r[i+1]);
	}
	FOR(i,1,n)gmax(to[i],to[i-1]),ans+=to[i]-i+1;
	cout<<ans;
	RE 0;
}