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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int l[805],r[805],lenl,lenr;
int cnt,ch[2005][10],dep[2005],fail[2005],val[2005][10][805];
bool fl[2005],fr[2005];
int dp[2005][2005],cost[2005][2005][10];
int out[2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string sl,sr;
	cin>>sl>>sr;
	for(auto u:sl)l[++lenl]=u-'0';
	for(auto u:sr)r[++lenr]=u-'0';
	int it=lenr;
	while(r[it]==9)it--;
	if(!it){
		lenr++;
		r[1]=1;
		FOR(i,2,lenr)r[i]=0;
	}else{
		FOR(i,it+1,lenr)r[i]=0;
		r[it]++;
	}
	int now=0;fl[now]=1;
	FOR(i,1,lenl){
		ch[now][l[i]]=++cnt;
		now=ch[now][l[i]];
		dep[now]=i;fl[now]=1;
	}
	now=0;fr[now]=1;
	FOR(i,1,lenr){
		if(!ch[now][r[i]])ch[now][r[i]]=++cnt;
		now=ch[now][r[i]];
		dep[now]=i;fr[now]=1;
	}
	queue<int> q;
	rep(i,0,10)if(ch[0][i])q.emplace(ch[0][i]);
	while(!q.empty()){
		int now=q.front();q.pop();
		rep(i,0,10){
			if(ch[now][i]){
				fail[ch[now][i]]=ch[fail[now]][i];
				q.emplace(ch[now][i]);
			}else{
				ch[now][i]=ch[fail[now]][i];
			}
		}
	}
	FOR(i,0,cnt){
		int now=i;
		while(1){
			if(fl[now]&&dep[now]<lenl)val[i][l[dep[now]+1]][lenl-dep[now]]--;
			if(fr[now]&&dep[now]<lenr)val[i][r[dep[now]+1]][lenr-dep[now]]++;
			if(!now)break;
			now=fail[now];
		}
		for(int j=8;j>=0;j--)FOR(k,0,800)val[i][j][k]+=val[i][j+1][k];
		rep(j,0,10)FOR(k,1,800)val[i][j][k]+=val[i][j][k-1];
	}
	FILL(dp,-1);
	int n;cin>>n;
	FOR(now,0,cnt)dp[n][now]=0;
	for(int i=n-1;i>=0;i--)FOR(now,0,cnt){
		rep(nxt,0,10)if(dp[i+1][ch[now][nxt]]>=0){
			int hav=dp[i+1][ch[now][nxt]];
			if(nxt){
				hav-=min(n-i,lenl-1);
				hav+=min(n-i,lenr-1);
			}
			if(nxt<9)hav+=val[now][nxt+1][min(800,n-i)];
			cost[i][now][nxt]=hav-dp[i+1][ch[now][nxt]];
			gmax(dp[i][now],hav);
		}
	}
	now=0;
	cout<<dp[0][0]<<'\n';
	rep(i,0,n){
		rep(nxt,0,10)if(dp[i+1][ch[now][nxt]]+cost[i][now][nxt]==dp[i][now]){
			cout<<nxt;
			now=ch[now][nxt];break;
		}
	}
	RE 0;
}