#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[20],tk,pw[20][10],er[10],mod=998244353;
P<int,int> dp[20][1024][2];
int count(int t){
	int cnt=0;
	while(t){
		t=t&(t-1);
		cnt++;
	}
	RE cnt;
}
void add(int &x,int y){
	x=x+y;
	if(x>=mod)x-=mod;
}
P<int,int> dfs(int p,int state,bool f){
	if(!p)RE MP(1,0);
	if(dp[p][state][f]!=MP(-1ll,-1ll))RE dp[p][state][f];
	P<int,int> re=MP(0,0); 
	if(f){
		P<int,int> t;int tp;
		FOR(i,0,a[p]){
			tp=state|er[i];
			if(!state&&!i)tp=0;
			if(count(tp)>tk)continue;
			t=dfs(p-1,tp,i==a[p]);
			add(re.F,t.F);
			add(re.S,(t.S+t.F*pw[p-1][i]%mod)%mod);
		}
		RE dp[p][state][f]=re;
	}else{
		P<int,int> t;int tp;
		FOR(i,0,9){
			tp=state|er[i];
			if(!state&&!i)tp=0;
			if(count(tp)>tk)continue;
			t=dfs(p-1,tp,0);
			add(re.F,t.F);
			add(re.S,(t.S+t.F*pw[p-1][i]%mod)%mod);
		}
		RE dp[p][state][f]=re;
	}
}
int solve(int t){
	int len=0;
	while(t){
		a[++len]=t%10;
		t/=10;
	}
	FOR(i,1,len)FOR(j,0,1023)FOR(u,0,1)dp[i][j][u]=MP(-1ll,-1ll);
	RE dfs(len,0,1).S;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l,r;
	cin>>l>>r>>tk;
	er[0]=1;
	FOR(i,1,9)er[i]=er[i-1]*2;
	rep(i,0,18){
		FOR(j,0,9){
			if(!i)pw[i][j]=j;
			else{
				pw[i][j]=pw[i-1][j]*10%mod;
			}
		}
	}
	cout<<(solve(r)-solve(l-1)+mod)%mod;
	RE 0;
}