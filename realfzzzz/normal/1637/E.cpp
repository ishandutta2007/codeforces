#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5;
int n,m,a[maxn],ord[maxn],n2,a2[maxn],cnt[maxn];
vector<int> vec[maxn],vec2,g[maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) ord[i]=a[i];
		sort(ord+1,ord+n+1);
		n2=unique(ord+1,ord+n+1)-ord-1;
		for(int i=1;i<=n;i++)
			a2[i]=lower_bound(ord+1,ord+n2+1,a[i])-ord;
		for(int i=1;i<=n2;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[a2[i]]++;
		for(int i=1;i<=n;i++) vector<int>().swap(vec[i]);
		for(int i=n2;i>0;i--) vec[cnt[i]].push_back(i);
		vector<int>().swap(vec2);
		for(int i=1;i<=n;i++)
			if(vec[i].size()) vec2.push_back(i);
		for(int i=1;i<=n2;i++) vector<int>().swap(g[i]);
		for(int i=1;i<=m;i++){
			int x,y;
			x=lower_bound(ord+1,ord+n2+1,read())-ord;
			y=lower_bound(ord+1,ord+n2+1,read())-ord;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		ll ans=0;
		for(int i:vec2) for(int j:vec2) if(i<=j){
			int mx=0;
			for(int x:vec[i]){
				for(int y:g[x]) vis[y]=1;
				for(int y:vec[j]) if(x!=y&&!vis[y]){
					mx=max(mx,ord[x]+ord[y]);
					break;
				}
				for(int y:g[x]) vis[y]=0;
			}
			ans=max(ans,1ll*(i+j)*mx);
		}
		printf("%lld\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}