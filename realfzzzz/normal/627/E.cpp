#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e3+5,maxk=10+5;
int r,c,n,k,x[maxn],y[maxn+maxk];
vector<int> q[maxn],q2[maxn];
int pre[maxn+maxk],nxt[maxn+maxk],t[maxn];
ll calc(int u){
	return 1ll*(y[u]-y[pre[u]])*(c+1-y[t[u]]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	r=readint();
	c=readint();
	n=readint();
	k=readint();
	for(int i=1;i<=n;i++){
		x[i]=readint();
		y[i]=readint();
		q[x[i]].push_back(i);
	}
	ll ans=0;
	for(int i=1;i<k;i++){
		nxt[n+i]=n+i+1;
		pre[n+i+1]=n+i;
		y[n+i]=c+1;
	}
	t[n+1]=n+k;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++) vector<int>().swap(q2[j]);
		for(int j=i;j<=r;j++)
			for(int u:q[j]) q2[y[u]].push_back(u);
		int v=n+1;
		for(int j=c;j>0;j--) for(int u:q2[j]){
			nxt[u]=v;
			pre[v]=u;
			t[u]=pre[t[v]];
			v=u;
		}
		pre[v]=0;
		ll res=0;
		for(int j=c;j>0;j--) for(int u:q2[j]) res+=calc(u);
		ans+=res;
		for(int j=r;j>i;j--){
			for(int u:q[j]){
				res-=calc(u);
				if(nxt[u]<=n) res-=calc(nxt[u]);
				nxt[pre[u]]=nxt[u];
				pre[nxt[u]]=pre[u];
				if(nxt[u]<=n) res+=calc(nxt[u]);
				int v=pre[u];
				for(int h=1;h<k&&v;h++){
					res-=calc(v);
					t[v]=nxt[t[v]];
					res+=calc(v);
					v=pre[v];
				}
			}
			ans+=res;
		}
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}