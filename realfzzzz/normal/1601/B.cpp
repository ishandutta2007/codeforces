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
const int maxn=3e5+5;
int n,a[maxn],b[maxn];
vector<int> vec[maxn];
int fa[maxn];
int find(int u){
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
int d[maxn],p1[maxn],p2[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	for(int i=0;i<=n;i++) vec[i+b[i]].push_back(i);
	for(int i=0;i<=n+1;i++) fa[i]=i;
	queue<int> q;
	q.push(n);
	for(int w:vec[n]) fa[w]=w+1;
	while(q.size()){
		int u=q.front();
		if(!u) break;
		q.pop();
		int v=find(max(u-a[u],0));
		while(v<=u){
			d[v+b[v]]=d[u]+1;
			q.push(v+b[v]);
			for(int w:vec[v+b[v]]) fa[w]=w+1;
			p1[v+b[v]]=u;
			p2[v+b[v]]=v;
			v=find(v);
		}
	}
	if(!d[0]){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",d[0]);
	int u=0;
	vector<int> ans;
	while(u<n){
		ans.push_back(p2[u]);
		u=p1[u];
	}
	for(int i=d[0]-1;i>=0;i--) printf("%d ",ans[i]);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}