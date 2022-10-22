#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
char c[205];
int len[205],a[11][205];
int pos[11][52][2],cnt[11][52];
int n;
int dp[52][1<<10];
P<int,int> lst[52][1<<10];
V<P<int,int> > v[52][1<<10];
V<P<int,int> > vp[125];
int it[11];
int used[52][1<<10];
void solve(){
	scanf("%d",&n);
	FILL(cnt,0);FILL(pos,0);
	rep(i,0,52)rep(j,0,1<<n)v[i][j].clear();
	FILL(used,0);
	rep(i,0,n){
		scanf("%s",c+1);
		len[i]=strlen(c+1);
		FOR(j,1,len[i]){
			if(c[j]<='Z'){
				a[i][j]=c[j]-'A';
			}else a[i][j]=c[j]-'a'+26;
		}
		FOR(j,1,len[i]){
			if(cnt[i][a[i][j]]){
				pos[i][a[i][j]][1]=j;
			}else pos[i][a[i][j]][0]=j;
			cnt[i][a[i][j]]++;
		}
	}
	FILL(dp,0);
	rep(j,0,52){
		rep(mask,0,1<<n){
			bool ff=1;
			rep(i,0,n)if(mask&(1<<i)){
				if(cnt[i][j]<2){
					ff=0;break;
				}else {
					it[i]=pos[i][j][1];
				}
			}else{
				if(cnt[i][j]==0){
					ff=0;break;
				}else it[i]=pos[i][j][0];
			}
			if(!ff)continue;
			rep(to,0,52){
				int tom=0;
				bool ff=1;
				rep(i,0,n)if(cnt[i][to]&&pos[i][to][0]>it[i]){
					
				}else if(cnt[i][to]==2&&pos[i][to][1]>it[i]){
					tom^=(1<<i);
				}else {
					ff=0;break;
				}
				if(ff){
					v[j][mask].PB(MP(to,tom));
				}
			}
		}
	}
	rep(i,0,125)vp[i].clear();
	rep(i,0,52){
		bool ff=1;
		rep(j,0,n)if(!cnt[j][i]){
			ff=0;break;
		}
		if(ff)vp[1].PB(MP(i,0)),dp[i][0]=1;;
		
	}
	P<int,int> ans=MP(-1,-1);
	rep(i,0,52)rep(j,0,1<<n)lst[i][j]=MP(-1,-1);
	FOR(i,1,120){
		if(vp[i].empty()){
			if(!vp[i-1].empty())ans=vp[i-1].back();else ans=MP(-1,-1);
			break;
		}
		for(auto nowp:vp[i])if(dp[nowp.F][nowp.S]==i&&used[nowp.F][nowp.S]<i){
			used[nowp.F][nowp.S]=i;
			for(auto u:v[nowp.F][nowp.S]){
				if(dp[u.F][u.S]<i+1){
					dp[u.F][u.S]=i+1;
					vp[i+1].PB(u);
					lst[u.F][u.S]=nowp;
				}
			}
		}
	}
	string as="";
	while(ans.F!=-1){
		if(ans.F<26){
			as+=(char)(ans.F+'A');
		}else as+=(char)(ans.F-26+'a');
		ans=lst[ans.F][ans.S];
	}
	reverse(ALL(as));
	cout<<as.size()<<'\n';
	cout<<as<<'\n';
}
signed main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
	RE 0;
}