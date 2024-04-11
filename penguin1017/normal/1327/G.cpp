#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=1e3+9;
const ll inf=1e18;
const ll mod=998244353;
ll sum[14][N],dp[1<<14][N];
int nxt[14][N];
char s[(int)4e5+9];
namespace ACauto{
	int nxt[N][14],c,fail[N],rt=0,fa[N];
	ll v[N];
	void init(){
		memset(nxt,0,sizeof nxt);
		memset(fail,0,sizeof fail);
		memset(fa,0,sizeof fa);
		memset(v,0,sizeof v);
		c=1; 
	}
	void add(char *s,int val){
		int p=rt;
		int len=strlen(s);
		rep(i,0,len){
			if(!nxt[p][s[i]-'a'])fa[c]=p,nxt[p][s[i]-'a']=c++;
			p=nxt[p][s[i]-'a'];
		}
		v[p]+=val;
	}
	void build(){
		queue<int> q;q.push(0); 
		while(!q.empty()){
			int u=q.front();q.pop();
			rep(i,0,14){
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
}
void upd(ll &a,ll b){
	if(a<b)a=b;
}
int main(){
	ACauto::init();
	int n,c;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%s%d",s,&c);
		ACauto::add(s,c);
	}
	ACauto::build();
	scanf("%s",s);
	int len=strlen(s);
	ll val=0;
	int p=0;
	rep(i,0,len){
		if(s[i]=='?')break;
		p=ACauto::nxt[p][s[i]-'a'];
		val+=ACauto::v[p];
	}
	rep(i,0,1<<14)rep(j,0,N)dp[i][j]=-inf;
	dp[0][p]=val;
	int k=0;
	rep(pp,0,len){
		if(s[pp]=='?'){
			int pos=pp+1;
			rep(i,0,ACauto::c){
				p=i;
				rep(j,pos,len){
					if(s[j]=='?')break;
					p=ACauto::nxt[p][s[j]-'a'];
					sum[k][i]+=ACauto::v[p];
				}
				nxt[k][i]=p;
			}
			++k;
		}
	}
	ll ans=-inf;
	rep(mask,0,1<<14){
		int t=__builtin_popcount(mask);
		if(t>k)continue;
		if(t==k){
			rep(i,0,ACauto::c)upd(ans,dp[mask][i]);
			continue;
		}
		rep(i,0,ACauto::c){
			int temp=~mask;
			rep(j,0,14){
				if(temp&&(1<<j)){
					p=ACauto::nxt[i][j];
					upd(dp[mask^(1<<j)][nxt[t][p]],dp[mask][i]+ACauto::v[p]+sum[t][p]);
				}
			}
		}
	}
	cout<<ans;
}