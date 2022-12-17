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
const int maxn=1e5+5;
int n,m,a[maxn],b[maxn];
typedef pair<int,int> pii;
pii f[maxn],g[maxn];
int h[maxn];
bool vis[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	m=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++) g[i]={2e9,0};
	for(int i=1;i<=n;i++)
		if(a[i]>=0){
			int l=0,r=n;
			while(l<r){
				int mid=l+(r-l+1)/2;
				if(g[mid].first<a[i]) l=mid;
				else r=mid-1;
			}
			f[i]={r+1,g[r].second};
			g[r+1]=min(g[r+1],{a[i],i});
		}
		else{
			int cur=n;
			for(int j=m;j>0;j--){
				while(g[cur].first>=b[j]) cur--;
				if(j==m) f[i]={cur+1,g[cur].second};
				g[cur+1]=min(g[cur+1],{b[j],i});
			}
		}
	pii ans={0,0};
	for(int i=1;i<=n;i++) ans=max(ans,{f[i].first,i});
	int u=ans.second,l=ans.first,lst=n+1,cur=m;
	a[n+1]=2e9;
	while(l){
		if(a[u]>=0){
			lst=u;
			u=f[u].second;
		}
		else{
			bool flag=0;
			for(int i=1;i<u;i++)
				if(a[i]>=0&&f[i].first==l&&a[i]<a[lst]){
					u=i;
					flag=1;
					break;
				}
			if(flag) continue;
			while(b[cur]>=a[lst]) cur--;
			a[u]=b[cur];
			vis[cur]=1;
			lst=u;
			while(u&&a[u]>=0) u--;
			for(int i=u+1;i<lst;i++)
				if(a[i]>=0&&f[i].first==l-1&&a[i]<a[lst]){
					u=i;
					break;
				}
		}
		l--;
	}
	cur=1;
	for(int i=1;i<=n;i++) if(a[i]<0){
		while(vis[cur]) cur++;
		a[i]=b[cur++];
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}