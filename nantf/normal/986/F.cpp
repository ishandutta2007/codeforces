#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int maxn=100010,maxm=33333333,m=32000000,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct ques{
	ll n,k;
	int id;
	bool operator<(const ques &q)const{return k<q.k;}
}q[maxn];
ll tmp[22],f[maxn];
int T,pr[maxm/10],pl,tl;
bool vis[maxm],ans[maxn],flag;
priority_queue<PII,vector<PII>,greater<PII> > pq;
void init(){
	FOR(i,2,m){
		if(!vis[i]) pr[++pl]=i;
		FOR(j,1,pl){
			int k=i*pr[j];
			if(k>m) break;
			vis[k]=true;
		}
	}
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b) return x=1,y=0,a;
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main(){
	init();
	T=read();
	FOR(i,1,T){
		ll n=read(),k=read();
//		if(i==1 && n==1443) flag=true;
		q[i]=(ques){n,k,i};
	}
	sort(q+1,q+T+1);
	FOR(i,1,T){
		ll k=q[i].k,ttt=k;
		tl=0;
		FOR(j,1,pl) if(ttt%pr[j]==0){
			tmp[++tl]=pr[j];
			while(ttt%pr[j]==0) ttt/=pr[j]; 
		}
		if(ttt>1) tmp[++tl]=ttt;
		if(tl>=3){
			assert(tmp[1]<=1e5);
			FOR(i,0,tmp[1]-1) f[i]=2e18;
			f[0]=0;
			while(!pq.empty()) pq.pop();
			pq.push(MP(f[0],0));
			while(!pq.empty()){
				int u=pq.top().second;ll d=pq.top().first;
				pq.pop();
				if(f[u]!=d) continue;
				FOR(i,2,tl){
					int v=(u+tmp[i])%tmp[1];
					if(d+tmp[i]<f[v]) pq.push(MP(f[v]=d+tmp[i],v));
				}
			}
		}
		FOR(j,i,T){
			if(q[j].k!=k){i=j-1;break;}
			ll n=q[j].n;
			if(!tl) ans[q[j].id]=false;
			else if(tl==1) ans[q[j].id]=n%tmp[1]==0;
			else if(tl==2){
				ll a=tmp[1],b=tmp[2],x,y,d=exgcd(a,b,x,y);
				assert(d==1);
				assert(abs(y)<a);
				y=(y+a)%a; 
				y=n%a*y%a;
				ans[q[j].id]=b*y<=n;
			}
			else ans[q[j].id]=f[n%tmp[1]]<=n; 
			if(flag && q[j].id==282) printf("%d\n",tl); 
			if(j==T) i=T;
		}
	}
	if(!flag) FOR(i,1,T) puts(ans[i]?"YES":"NO");
}