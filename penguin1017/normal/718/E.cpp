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
const int N=1e5+20;
const ll mod=998244353;
const ll Inf=1e18;
/*
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
int jie[N],inv[N];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
*/
bool vis[N];
int f[N][8],h[8][8];
int d[8][8][1<<8][1<<8];
int sum[8][1<<8];
char s[N];
vi g[8];
queue<int> q;
int gs(int id){
	int mask=0;
	rep(i,0,8)mask|=(f[id][i]!=h[s[id]][i])<<i;
	return mask;
}
int main(){
	rep(i,0,N)rep(j,0,8)f[i][j]=N;
	rep(i,0,8)rep(j,0,8)h[i][j]=N;
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,0,n)s[i]-='a',g[s[i]].pb(i);
	rep(i,0,8){
		h[i][i]=0;
		memset(vis,0,sizeof vis);
		for(auto v:g[i]){
			q.push(v);
			f[v][i]=0;
			vis[v]=1;
		}
		vis[i+n]=1;
		while(q.size()){
			int u=q.front();
			q.pop();
			if(u&&!vis[u-1]){
				vis[u-1]=1;
				f[u-1][i]=f[u][i]+1;
				q.push(u-1);
			}
			if(u<n-1&&!vis[u+1]){
				vis[u+1]=1;
				f[u+1][i]=f[u][i]+1;
				q.push(u+1);
			}
			if(!vis[s[u]+n]){
				vis[s[u]+n]=1;
				h[s[u]][i]=f[u][i];
				for(auto v:g[s[u]]){
					if(!vis[v]){
						vis[v]=1;
						f[v][i]=f[u][i]+1;
						q.push(v);
					}
				}
			}
		}
	} 
	rep(i,0,8)rep(j,0,8)rep(mask,0,1<<8)rep(_,0,1<<8){
		d[i][j][mask][_]=N;
		rep(a,0,8)d[i][j][mask][_]=min(d[i][j][mask][_],h[i][a]+h[a][j]+(mask>>a&1)+(_>>a&1)+1);
	}
	int mx=0;
	ll ans=0;
//	cout<<gs(3)<<' '<<gs(0)<<"mask\n";
	rep(i,0,n){
		rep(j,max(0,i-15),i){
			int dis=min(i-j,d[s[i]][s[j]][gs(i)][gs(j)]);
			if(dis>mx)mx=dis,ans=0;
		/*	if(mx==3){
				cout<<i<<' '<<j<<"check\n";
				system("pause");
			}*/
			if(dis==mx)++ans;
		}
		int mask=gs(i);
		rep(j,0,8)rep(_,0,1<<8){
			if(!sum[j][_])continue;
			if(d[s[i]][j][mask][_]>mx)mx=d[s[i]][j][mask][_],ans=0;
		/*	if(mx==3){
				cout<<i<<' '<<j<<' '<<_<<"check2\n";
				system("pause");
			}*/
			if(d[s[i]][j][mask][_]==mx)ans+=sum[j][_];
		}
		if(i>=15)sum[s[i-15]][gs(i-15)]++;
	}
	printf("%d %lld\n",mx,ans);
	//pre();
}
// a b aaccddeeffgghhb