#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=210;
const int mod=1e9+7;
const ll Inf=1e18;
int n,m,k; 
int l[N],r[N],s[N];
struct AC{
	int nxt[N][20],c=1,fail[N],rt,fa[N];
	int v[N];
	void init(){
		memset(nxt,0,sizeof (nxt)*c);
		memset(fail,0,sizeof (fail)*c);
		memset(fa,0,sizeof (fa)*c);
		memset(v,0,sizeof (v)*c);
		c=1;
		rt=0;
	}
	void add(int *s,const int &val){
		int p=rt;
		rep(i,1,s[0]+1){
			if(!nxt[p][s[i]])fa[c]=p,nxt[p][s[i]]=c++;
			p=nxt[p][s[i]];
		}
		v[p]+=val;
	}
	void build(){
		queue<int> q;q.push(0);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			rep(i,0,20){
				if(nxt[u][i]){
					int p=nxt[u][i];
					q.push(p);
					if(u)fail[p]=nxt[fail[u]][i];
				}
				else nxt[u][i]=nxt[fail[u]][i];
			}
			v[u]+=v[fail[u]];
		}
	}
}ac;
void read(int *s){
	scanf("%d",&s[0]);
	rep(i,1,s[0]+1)scanf("%d",&s[i]);
}
int dp[210][510][210][2];
int solve(int *s,int pos,int sum,int u,bool lim,bool lead){
	if(sum>k)return 0;
	if(!pos)return 1;
	if(dp[pos][sum][u][lead]!=-1&&!lim)return dp[pos][sum][u][lead];
	int ans=0;
	int up=lim?s[pos]:m-1;
	rep(i,0,up+1){
		int v=(lead&&!i)?0:ac.nxt[u][i]; 
		ans=(ans+solve(s,pos-1,sum+ac.v[v],v,lim&(i==up),lead&(!i)));
		if(ans>=mod)ans-=mod;
	}
	if(!lim)dp[pos][sum][u][lead]=ans;
	return ans;
}
int main(){
	//pre();
	scanf("%d%d%d",&n,&m,&k);
	int len=0;
	read(l);
	read(r);
	ac.init();
	rep(i,0,n){
	//	cout<<i<<"??\n"; 
		read(s);
		int x;
		scanf("%d",&x);
		ac.add(s,x);
	}
	ac.build() ;
//	rep(i,1,ac.c+1)cout<<i<<' '<<ac.v[i]<<"check\n";
	memset(dp,-1,sizeof dp); 
	l[l[0]]--;
	per(i,1,l[0]+1){
		if(l[i]<0)l[i]+=m,l[i-1]--;
	} 
	reverse(l+1,l+1+l[0]);
	reverse(r+1,r+1+r[0]); 
	printf("%d\n",(solve(r,r[0],0,0,1,1)-solve(l,l[0],0,0,1,1)+mod)%mod);
}