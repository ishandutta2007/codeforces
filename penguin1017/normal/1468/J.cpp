#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define vi vector<int> 
#define pb push_back
using namespace std;
const int N=5e5+9;
struct node{
	int u,v,w;
	node(int u=0,int v=0,int w=0):u(u),v(v),w(w){} 
}p[N];
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k,m;
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,n+1)fa[i]=i;
		rep(i,0,m){
			scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
		}
		ll sum=0;
		sort(p,p+m,[](node a,node b){return a.w<b.w;});
		int ok=0,pos=0;
		rep(i,0,m){
			int u=p[i].u,v=p[i].v,w=p[i].w;
			u=find(u),v=find(v);
			if(u==v)continue;
			fa[u]=v;
			pos=i;
			sum+=k>=w?0:w-k;
			if(w>=k)ok=1; 
		}
		if(ok)printf("%lld\n",sum);
		else {
			sum=2e9;
		 	rep(i,pos,m)sum=min((int)sum,abs(p[i].w-k));
		 	printf("%lld\n",sum);
		}
	}
}