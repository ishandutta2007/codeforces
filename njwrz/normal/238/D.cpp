#include<bits/stdc++.h>
#define ll long long
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
int cnt[2000005][10];
int fir[200005],sec[200005],lst[200005],nxt[200005];
int p;
int n;
char s[200005];
void erase(int x){
	nxt[lst[x]]=nxt[x];
	lst[nxt[x]]=lst[x];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>n>>q;
	FOR(i,1,n){
		cin>>s[i+n+1];
	}
	FOR(i,1,n+1)s[i]='>';
	int now=n+1;
	p=1;
	FOR(i,1,n+n+1)lst[i]=i-1,nxt[i]=i+1;
	FILL(fir,-1);FILL(sec,-1);
	int tap=1;
	set<int> ts;
	FOR(i,1,n+n+1)ts.emplace(i);
	while(1){
		int to;
		if(fir[now]==-1){
			fir[now]=p;
		}
		if(tap==1){
			to=nxt[now];
		}else to=lst[now];
		if(tap==0){
			auto u=ts.lwb(to+1);
			V<int> era;
			while(u!=ts.end()&&(*u)<=now){
				sec[*u]=p;
				era.PB(*u);
				++u;
			}
			for(auto u:era)ts.erase(u);
		}
		FOR(i,0,9)cnt[p][i]=cnt[p-1][i];
		if(isdigit(s[now])){
			cnt[p][s[now]-'0']++;
		}
		if(now==n+n+2)break;
		if(s[now]=='0'){
			erase(now);
		}else if(isdigit(s[now]))s[now]--;
		if(to<0||to>n+n+2)break;
		++p;
		if(s[to]=='<'||s[to]=='>'){
			if(s[now]=='<'||s[now]=='>')erase(now);
			if(s[to]=='<')tap=0;else tap=1;
		}
		now=to;
	}
	FOR(i,1,q){
		int l,r;
		cin>>l>>r;l+=n+1;r+=n+1;
		int st=fir[l];
//		cout<<sec[l]<<' '<<fir[r+1]<<'\n';
		int ed;
		if(sec[l]==-1){
			ed=fir[r+1]-1;
		}else ed=min(sec[l],fir[r+1]-1);
		rep(j,0,10)cout<<cnt[ed][j]-cnt[st-1][j]<<' ';
		cout<<'\n';
	}
	RE 0;
}