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
int ch[300005][26];
int cnt[300005],num;
char c[300005];
int len,B=sqrt(300000);
int mod=998244353,p37[300005],p[300005];
set<P<int,int> > s;
void update(int &x,int now,int add){
	if(!x)x=++num;
	if(now==len+1){
		cnt[x]+=add;RE;
	}
	update(ch[x][c[now]-'a'],now+1,add);
}
int solve(){
	int re=0;
	FOR(i,1,len){
		re=(re*37ll+(c[i]-'a'))%mod;
	}
	RE re;
}
int get(int x,int l,int r){
	if(!x)RE 0;
	int re=cnt[x];
	if(l==r+1)RE re;
	RE re+get(ch[x][c[l]-'a'],l+1,r);
}
void solve2(){
	FOR(i,1,len){
		p[i]=(p[i-1]*37ll+c[i]-'a')%mod;
	}
}
int qry(int l,int r){
	RE (p[r]-1ll*p[l-1]*p37[r-l+1]%mod+mod)%mod;
}
int root;
signed main(){
	int T;
	scanf("%d",&T);
	p37[0]=1;
	FOR(i,1,300000)p37[i]=p37[i-1]*37ll%mod;
	FOR(_,1,T){
		int tap;
		scanf("%d %s",&tap,c+1);
		len=strlen(c+1);
		if(tap==1){
			if(len<=B)update(root,1,1);
			else s.emplace(MP(len,solve()));
		}else if(tap==2){
			if(len<=B)update(root,1,-1);
			else s.erase(MP(len,solve()));
		}else{
			ll ans=0;
			FOR(i,1,len){
				ans+=get(root,i,min(i+B-1,len));
			}
			solve2();
			for(auto u:s){
				FOR(i,1,len-u.F+1){
					if(qry(i,i+u.F-1)==u.S)ans++;
				}
			}
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
	RE 0;
}