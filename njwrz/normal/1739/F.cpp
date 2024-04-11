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
#define sz(x) ((int)x.size())
using namespace std;
const int inf=1e18;
int n;
int ch[10005][12],hav[10005],root,cnt,fail[10005];
int dp[1<<12][4005];
P<int,int> lst[1<<12][4005];
char c[100],ans[12];
bool vis[26];
V<P<string,int> > v;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	root=++cnt;
	cin>>n;
	FOR(i,1,n){
		int x;
		cin>>x;
		string ts;
		cin>>ts;
		int s=50,t=51;
		c[s]=ts[0];c[t]=ts[1];
		int it=t;
		bool f=1;
		rep(j,2,sz(ts)){
			if(it>s&&c[it-1]==ts[j]){
				it--;
			}else if(it<t&&c[it+1]==ts[j]){
				it++;
			}else{
				if(it==s){
					--s;it=s;
					c[s]=ts[j];
				}else if(it==t){
					++t;it=t;
					c[t]=ts[j];
				}else{
					f=0;break;
				}
			}
		}
		if(!f)continue;
		FILL(vis,0);
		string now;
		FOR(j,s,t)now+=c[j];
		for(auto u:now){
			if(vis[u-'a']){
				f=0;break;
			}
			vis[u-'a']=1;
		}
		if(!f)continue;
		int at=root;
		rep(j,0,sz(now)){
			if(!ch[at][now[j]-'a'])ch[at][now[j]-'a']=++cnt;
			at=ch[at][now[j]-'a'];
		}
		v.PB(MP(now,x));
		reverse(ALL(now));
		at=root;
		rep(j,0,sz(now)){
			if(!ch[at][now[j]-'a'])ch[at][now[j]-'a']=++cnt;
			at=ch[at][now[j]-'a'];
		}
		v.PB(MP(now,x));
	}
	FOR(i,1,cnt){
		for(auto u:v){
			int now=i;
			rep(j,0,(int)u.F.size()){
				now=ch[now][u.F[j]-'a'];
				if(!now)break;
			}
			if(now)hav[now]+=u.S;
		}
	}
	queue<int> q;
	rep(i,0,12)if(ch[root][i])q.emplace(ch[root][i]),fail[ch[root][i]]=root;
	while(!q.empty()){
		int now=q.front();q.pop();
		rep(i,0,12)if(ch[now][i]){
			fail[ch[now][i]]=max(ch[fail[now]][i],1ll);
			q.emplace(ch[now][i]);
		}else ch[now][i]=max(ch[fail[now]][i],1ll);
	}
	rep(mask,0,(1<<12)-1)FOR(i,1,cnt)dp[mask][i]=-inf;
	dp[0][1]=0;
	rep(mask,0,(1<<12)-1)FOR(at,1,cnt)if(dp[mask][at]>=0){
		rep(nxt,0,12)if(!(mask&(1<<nxt))){
			int to=ch[at][nxt],val=dp[mask][at]+hav[to];
			gmax(to,1ll);
			if(val>=dp[mask|(1<<nxt)][to]){
				dp[mask|(1<<nxt)][to]=val;
				lst[mask|(1<<nxt)][to]=MP(mask,at);
			}
		}
	}
	int msk=(1<<12)-1,now=1;
	FOR(i,1,cnt){
		if(dp[msk][i]>dp[msk][now])now=i;
	}
	for(int i=11;i>=0;i--){
		P<int,int> t=lst[msk][now];
		int cc=log2(t.F^msk);
		ans[i]=cc+'a';
		msk=t.F;now=t.S; 
	}
	rep(i,0,12)cout<<ans[i];
	RE 0;
}